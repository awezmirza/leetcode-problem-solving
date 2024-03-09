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

    bool solveTab(vector<int>& nums, int target){
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, 0));
        for(int i = 0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        for(int index = nums.size()-2;index>=0;--index){
            for(int tgt = 0;tgt <= target;tgt++){
                bool take = false;
                if(tgt - nums[index] >= 0)
                    take = dp[index+1][tgt - nums[index]];
                bool leave = dp[index+1][tgt];
                dp[index][tgt] = take | leave;
            }
        }
        return dp[0][target];
    }


    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) totalSum += num;
        if(totalSum%2 == 1) return false;
        int target = totalSum/2;

        bool ans = solveTab(nums,target);
        return ans;
    }
};