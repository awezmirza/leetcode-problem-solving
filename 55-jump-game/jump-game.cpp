class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            int j = i;
            while (j < n && j <= i + nums[i] && dp[i] == false) {
                dp[i] = dp[j];
                j++;
            }
        }
        return dp[0];
    }
};