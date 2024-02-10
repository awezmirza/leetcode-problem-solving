class Solution {
public:
    int firndCntPal(string &s, int i , int j){
        int cnt = 0;
        int n  = s.size();
        while(i>= 0 && j < n && s[i] == s[j]){
            i--, j++, cnt++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            // for odd
            int odd = firndCntPal(s,i,i);

            // for even
            int even = firndCntPal(s,i,i+1);

            ans += odd + even;
        }
        return ans;
    }
};