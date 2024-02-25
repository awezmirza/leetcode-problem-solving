class Solution {
public:

    // int robHelper(vector<int>& nums, int i){
    //     if(i >= nums.size()) return 0;
    //     int take = nums[i] + robHelper(nums, i+2);
    //     int leave = robHelper(nums, i+1);
    //     return max(take, leave);
    // }

    // int robHelper(vector<int>& nums, int i, vector<int>& dp){
    //     if(i >= nums.size()) return 0;
    //     if(dp[i] != -1) return dp[i]; 
    //     int take = nums[i] + robHelper(nums, i+2, dp);
    //     int leave = robHelper(nums, i+1, dp);
    //     return dp[i] = max(take, leave);
    // }

    int robHelper(vector<int>& nums){
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1;i<n;i++){
            int leave = dp[i-1];
            int take = nums[i];
            if(i>1) 
                take += dp[i-2];
            dp[i] = max(take, leave);
        }
        return dp[n-1];

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> arrayWithoutFirst, arrayWithoutLast;
        for(int i = 0;i<n;i++){
            if(i!=0) arrayWithoutFirst.push_back(nums[i]);
            if(i!=n-1) arrayWithoutLast.push_back(nums[i]);
        }

        int ans1 = robHelper(arrayWithoutFirst);
        int ans2 = robHelper(arrayWithoutLast);
        return max(ans1,ans2);
    }
};