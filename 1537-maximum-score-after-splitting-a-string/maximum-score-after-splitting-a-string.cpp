class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        int zeroes = 0;
        int ans = -1;
        for(auto ch : s ){
            if(ch == '1') ones++; 
        }
        for(int i = 0;i<n-1;i++){
            if(s[i] == '0') zeroes++;
            else ones--;
            ans = max(ans,zeroes + ones);
        }
        return ans;
    }
};