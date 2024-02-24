class Solution {
public:

    int robHelperSO(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1;i < n; i++){
            int leave = dp[i-1];

            int take = nums[i];
            if(i > 1) take+= dp[i-2];

            dp[i] = max(take,leave);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        
        int ans = robHelperSO(nums);
        return ans;
    }
};