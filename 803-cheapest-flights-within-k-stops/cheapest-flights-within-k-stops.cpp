class Solution {
public:

    int findCheapestPriceHelper(unordered_map<int,vector<pair<int,int>>>& allflights, int src, int dst, int k, vector<vector<vector<double>>>& dp){
        if(src == dst){
            return 0;
        }
        if(k<0) return INT_MAX;
        if(dp[src][dst][k] != -100) return dp[src][dst][k];
        double ans = INT_MAX;
        for(auto destAndWt : allflights[src]){
            int dest = destAndWt.first;
            int wt = destAndWt.second;
            int findAns = findCheapestPriceHelper(allflights, dest, dst, k-1,dp);
            ans = min(ans, (double) wt + findAns);
        }
        dp[src][dst][k] = ans;
        return ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k ) {
        unordered_map<int,vector<pair<int,int>>> allflights;
        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            allflights[from].push_back({to,cost});
        }

        // double ans = INT_MAX;
        // for(auto destAndWt : allflights[src]){
        //     int dest = destAndWt.first;
        //     int wt = destAndWt.second;
        //     ans = min(ans,(double) wt + findCheapestPriceHelper(allflights, dest, dst, k-1));
        // }
        vector<vector<vector<double>>> dp(n + 1,vector<vector<double>>(n + 1, vector<double>(k + 1, -100) ));
        double ans = findCheapestPriceHelper(allflights, src, dst, k, dp);
        if(ans == INT_MAX) return -1;


        return ans;
    }
};