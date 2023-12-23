class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0,y=0;
        unordered_set<string> s;
        s.insert("0,0");

        for(auto pat : path ){
            if(pat == 'N') y++;
            else if(pat == 'S') y--;
            else if(pat == 'E') x++;
            else x--;

            string cordinates = to_string(x) + ',' + to_string(y);
            if(s.find(cordinates) != s.end()) return true;
            s.insert( cordinates );
        }
        return false;
    }
};