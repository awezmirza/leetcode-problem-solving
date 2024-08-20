class Solution {
public:

    int solve(vector<int>& piles, int m, int i, int aliceTurn, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if (i >= n) {
            return 0;
        }

        if (dp[i][m][aliceTurn] != -1) {
            return dp[i][m][aliceTurn];
        }

        int pilesSum = 0;
        int ans = aliceTurn == 1 ? -1 : INT_MAX;
        for (int x = 1; (x <= 2 * m) && ((i + x - 1) < n); x++) {
            pilesSum += piles[i + x - 1];
            if (aliceTurn == 1) {
                ans = max(ans, pilesSum + solve(piles, max(x, m), i + x, 0, dp));
            } else {
                ans = min(ans, solve(piles, max(x, m), i + x, 1, dp));
            }
        }
        return dp[i][m][aliceTurn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n + 1, vector<int> (2, -1)));

        int ans = solve(piles, 1, 0, 1, dp);
        return ans;   
    }
};