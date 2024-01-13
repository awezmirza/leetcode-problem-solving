class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.size();
        
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        int cnt = 0;

        for(auto pr : mp){
            if(pr.second > 0){
                cnt += pr.second;
            }
        }
        return cnt;
     
    }
};