class Solution {
public:

    int dis(int ringSize, int currIdx, int nextIdx){
        int clkWise = abs(nextIdx - currIdx);
        int antiClk = ringSize - clkWise;
        return min(clkWise, antiClk);
    }

    int solve(string ring, string key, int ringIdx, int keyIdx, vector<vector<int>>& dp){
        if(keyIdx >= key.size()){
            return 0;
        }
        if(dp[keyIdx][ringIdx] != -1){
            return dp[keyIdx][ringIdx];
        }
        int minTotal = INT_MAX;
        for(int i = 0; i < ring.size(); i++){
            if(key[keyIdx] == ring[i]){
                int currTotal = dis(ring.size(), ringIdx, i) + 1 + solve(ring, key, i, keyIdx + 1, dp);
                minTotal = min(minTotal, currTotal);
            }
        }
        return dp[keyIdx][ringIdx] = minTotal;
    }

    int solveTab(string ring, string key){
        int m = key.size();
        int n = ring.size();
        
        vector<vector<int>> dp(n, vector<int> (m + 1, 0));

        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){

                int minTotal = INT_MAX;
                for(int k = 0; k < ring.size(); k++){
                    if(key[i] == ring[k]){
                        int currTotal = dis(ring.size(), j, k) + 1 + dp[k][i + 1];
                        minTotal = min(minTotal, currTotal);
                    }
                }
                dp[j][i] = minTotal;
            }
        }
        return dp[0][0];
    }

    int solveTabSO(string ring, string key){
        int m = key.size();
        int n = ring.size();
        
        vector<int> nextDP(n, 0);

        for(int i = m - 1; i >= 0; i--){
            vector<int> currDP(n, 0);
            for(int j = 0; j < n; j++){

                int minTotal = INT_MAX;
                for(int k = 0; k < ring.size(); k++){
                    if(key[i] == ring[k]){
                        int currTotal = dis(ring.size(), j, k) + 1 + nextDP[k];
                        minTotal = min(minTotal, currTotal);
                    }
                }
                currDP[j] = minTotal;
            }
            nextDP = currDP;
        }
        return nextDP[0];
    }

    int findRotateSteps(string ring, string key) {
        int ans = solveTabSO(ring, key);
        return ans;
    }
};