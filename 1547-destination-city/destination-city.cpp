class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
    int n = paths.size();
    unordered_set<string> us;
    for(auto elem : paths){ us.insert(elem[0]);}
    for(auto elem : paths){
    if(us.find(elem[1]) == us.end()
){return elem[1];}
    }
        return 0;
    }
};