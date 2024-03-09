class Solution {
public:

    bool solve(vector<int>& nums, int sum1, int index, int& totalSum, vector<vector<int>>& dp){
        if(index >= nums.size()){
            if(sum1 == totalSum - sum1) return true;
            return false;
        }
        if(dp[index][sum1] != -1) return dp[index][sum1];

        bool nu1 = solve(nums, sum1 + nums[index], index+1, totalSum, dp);
        bool nu2 = solve(nums, sum1, index+1, totalSum, dp);
        return dp[index][sum1] = nu1 ||nu2;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num:nums) totalSum += num;
        vector<vector<int>> dp(nums.size(), vector<int> (totalSum, -1));
        bool ans = solve(nums,0,0, totalSum, dp);
        return ans;
    }
};