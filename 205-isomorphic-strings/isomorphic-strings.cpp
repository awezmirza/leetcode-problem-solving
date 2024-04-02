class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        vector<bool> used(256);
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(used[t[i]]) return false;
                mp[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;
    }
};