class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0,y=0;
        set<pair<int,int>> s;
        s.insert({0,0});

        for(auto pat : path ){
            if(pat == 'N') y++;
            else if(pat == 'S') y--;
            else if(pat == 'E') x++;
            else x--;
            if(s.find({x,y}) != s.end()) return true;
            s.insert({x,y});
        }
        return false;
    }
};