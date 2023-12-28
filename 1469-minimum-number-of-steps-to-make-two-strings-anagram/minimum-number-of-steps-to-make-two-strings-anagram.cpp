class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sFreq(26, 0);
        int n = s.length();
        for(int i = 0;i<n;i++){
            sFreq[s[i] - 'a']++;
            sFreq[t[i] - 'a']--;
        }
        
        int ans = 0;
        for(auto el : sFreq){
            if(el > 0){
                ans+= el;
            }
        }
        return ans;
    }
};