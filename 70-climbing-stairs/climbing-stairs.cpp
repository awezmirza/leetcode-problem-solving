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

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = climbStairsHelper(n,dp);
        return ans;
    }
};