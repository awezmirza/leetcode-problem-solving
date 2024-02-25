class Solution {
public:

    // int robHelper(vector<int>& nums, int i){
    //     if(i >= nums.size()) return 0;
    //     int take = nums[i] + robHelper(nums, i+2);
    //     int leave = robHelper(nums, i+1);
    //     return max(take, leave);
    // }

    int robHelper(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i]; 
        int take = nums[i] + robHelper(nums, i+2, dp);
        int leave = robHelper(nums, i+1, dp);
        return dp[i] = max(take, leave);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> arrayWithoutFirst, arrayWithoutLast;
        for(int i = 0;i<n;i++){
            if(i!=0) arrayWithoutFirst.push_back(nums[i]);
            if(i!=n-1) arrayWithoutLast.push_back(nums[i]);
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int ans1 = robHelper(arrayWithoutFirst,0, dp1);
        int ans2 = robHelper(arrayWithoutLast,0, dp2);
        return max(ans1,ans2);
    }
};