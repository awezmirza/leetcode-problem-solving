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

    int findRotateSteps(string ring, string key) {
        int n = key.size();
        int m = ring.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = solve(ring, key, 0, 0, dp);
        return ans;
    }
};