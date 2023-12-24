class Solution {
public:
    int minOperations(string s) {
        for(int i=0, n = s.size(), cnt = 0;i<n;i++){
            if((i&1 && s[i] == '0') || (!(i&1) && s[i] == '1')) cnt++;
            if(i==n-1) return min(cnt , n - cnt );
        }
        return 0;
    }
};