class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> mp;

        vector<vector<string>> ans;
        
        for(auto str:strs){
            string tempStr = str;
            sort(tempStr.begin(),tempStr.end());
            mp[tempStr].push_back(str);
        }
        for(auto el:mp){
            ans.push_back(el.second);
        }
        return ans;
        
    }
};