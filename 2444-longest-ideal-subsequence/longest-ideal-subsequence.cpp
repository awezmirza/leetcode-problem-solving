class Solution {
public:

    int solve(string s, int k, int index, char lastChar, vector<vector<int>>& dp){
        if(index >= s.size()){
            return 0;
        }

        if(dp[index][lastChar - 'a'] != -1){
            return dp[index][lastChar - 'a'];
        }

        int notTake = solve(s, k, index + 1, lastChar, dp);
        int take = 0;
        if(lastChar == '{' || abs(s[index] - lastChar) <= k){
            take = 1 + solve(s, k, index + 1, s[index], dp);
        }
        return dp[index][lastChar - 'a'] = max(take, notTake);
    }

    int solveTab(string s, int k){
        int n = s.size();

        vector<int> dp(27, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            int maxLength = 0;
            for(int j = 0; j < 26; j++){
                if(abs(s[i] - (j + 'a')) <= k){
                    maxLength = max(maxLength, 1 + dp[j]);
                }
            }
            dp[s[i] - 'a'] = maxLength;
            ans = max(ans, maxLength);
        }
        return ans;
    }

    int longestIdealString(string s, int k) {
        int ans = solveTab(s, k);
        return ans;
    }
};