class Solution {
public:
    int robHelper(vector<int>& nums, int lastIdx, vector<int>& dp){
        if(lastIdx >= nums.size()){
            return 0;
        }
        if(dp[lastIdx] != -1 ) return dp[lastIdx] ;
        int take = nums[lastIdx] + robHelper(nums,lastIdx + 2, dp);
        int leave = robHelper(nums , lastIdx + 1, dp);
        dp[lastIdx] = max(take, leave);
        return dp[lastIdx];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = robHelper(nums,0, dp);
        return ans;
    }
};