class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            int idx = 2 * i;
            if (s[idx] != s[idx + 1]) {
                ans++;
            }
        }
        return ans;
    }
};