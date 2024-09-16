class Solution {
public:

    int solve(string s, string t, int sPtr, int tPtr, vector<vector<int>>& dp) {
        int m = s.size();
        int n = t.size();
        if (tPtr >= n) {
            return 1;
        }
        if(sPtr >= m) {
            return 0;
        }
        if (dp[sPtr][tPtr] != -1) {
            return dp[sPtr][tPtr];
        }
        int take = 0;
        if (s[sPtr] == t[tPtr]) {
            take = solve(s, t, sPtr + 1, tPtr + 1, dp);
        }
        int leave = solve(s, t, sPtr + 1, tPtr, dp);
        return dp[sPtr][tPtr] = take + leave;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(s, t, 0, 0, dp); 
    }
};