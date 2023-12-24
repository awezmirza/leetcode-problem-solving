class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), cnt = 0;
        for(int i=0;i<n;i++){
            if( (i&1 && s[i] == '0') || (!(i&1) && s[i] == '1') ) cnt++;
        }
        return min(cnt , n - cnt );
    }
};