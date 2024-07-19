class Solution {
public:

    int solve (vector<int>& nums, int index, int lastNumIndex, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (lastNumIndex != -1 && dp[index][lastNumIndex] != -1) {
            return dp[index][lastNumIndex];
        }

        // Take
        int take = 0;
        if (lastNumIndex == -1 || nums[index] > nums[lastNumIndex]) {
            take = 1 + solve(nums, index + 1, index, dp);
        }

        // Not Take
        int notTake = solve(nums, index + 1, lastNumIndex, dp);

        if (lastNumIndex != -1) {
            dp[index][lastNumIndex] = max(take, notTake);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        int m = 2500;

        vector<vector<int>> dp(n, vector<int> (m, -1));

        int ans = solve(nums, 0, -1, dp);

        return ans;
    }
};