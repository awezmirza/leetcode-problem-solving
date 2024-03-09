class Solution {
public:

    bool solve(vector<int>& nums, int target, int index, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index >= nums.size() || target < 0) return false;
        
        if(dp[index][target] != -1) return dp[index][target];

        bool take = solve(nums, target - nums[index], index+1, dp);
        bool leave = solve(nums, target, index+1, dp);
        
        return dp[index][target] = take | leave;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum%2 == 1) return false;
        int target = totalSum/2;
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        bool ans = solve(nums,target, 0, dp);
        return ans;
    }
};