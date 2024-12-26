class Solution {

    int solve(vector<int>& nums, int target, int curr, int idx, vector<vector<int>>& dp) {
        int n = nums.size();
        if (idx >= n) {
            if (curr == target) {
                return 1;
            }
            return 0;
        }
        if (dp[idx][curr + 1000] != -1) {
            return dp[idx][curr + 1000];
        }

        // Without - 
        int without = solve(nums, target, curr + nums[idx], idx + 1, dp);

        // With - 
        int with = solve(nums, target, curr - nums[idx], idx + 1, dp);

        return dp[idx][curr + 1000] = without + with;
    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2002, -1));
        int ans = solve(nums, target, 0, 0, dp);
        return ans;
    }
};