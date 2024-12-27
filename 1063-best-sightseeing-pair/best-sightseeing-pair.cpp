class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = -1;
        vector<int> dp(n, -1);
        dp[0] = values[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(values[i] + i, dp[i - 1]);
        }
   
        for (int i = 1; i < n; i++) {
            ans = max(ans, dp[i - 1] + values[i]  - i);
        }
        return ans;
    }
};