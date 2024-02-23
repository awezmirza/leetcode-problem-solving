class Solution {
public:
    int climbStairsHelper(int n, vector<int>& dp){
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        if(dp[n] != -1) return dp[n];
        int ans = climbStairsHelper(n-1,dp) + climbStairsHelper(n-2,dp);
        dp[n] = ans;
        return ans;
    }

    int climbStairsHelperTab(int n){

        vector<int> dp(n+1,-1);
        dp[1] = 1;
        if(n>1)
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        int ans = climbStairsHelperTab(n);
        return ans;
    }
};