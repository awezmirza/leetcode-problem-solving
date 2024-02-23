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

    int climbStairsHelperTabSO(int n){
        if(n == 1) return 1;
        int prev1 = 2, prev2 = 1, ans = 2;
        for(int i = 3;i<=n;i++){
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }

    int climbStairs(int n) {
        int ans = climbStairsHelperTabSO(n);
        return ans;
    }
};