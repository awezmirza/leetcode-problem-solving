#define INTx3 tuple<int,int,int>
class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // SRC, {DEST, COST}
        unordered_map<int,vector<pair<int,int>>> allflights;
        for(auto& flight : flights){
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            allflights[from].push_back({to,cost});
        }
        
        queue< INTx3 > q;
        q.push({src,0,k});
        double ans = INT_MAX;
        vector<int> dist(n,INT_MAX);
        while(!q.empty()){
            auto [fsrc,fwt,fK] = q.front();

            if(fsrc == dst) ans = min(ans,(double) fwt);
            q.pop();
            if(fK < 0 || fwt > ans) continue;
            for(auto [to, cost] : allflights[fsrc]){
                int dis = fwt + cost;
                if(dis < dist[to]){
                    dist[to] = dis;
                    q.push({to, fwt + cost, fK-1});
                }
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};



// class Solution {
// public:

//     int findCheapestPriceHelper(unordered_map<int,vector<pair<int,int>>>& allflights, int src, int dst, int k, vector<vector<vector<double>>>& dp){
//         if(src == dst){
//             return 0;
//         }
//         if(k<0) return INT_MAX;
//         if(dp[src][dst][k] != -100) return dp[src][dst][k];
//         double ans = INT_MAX;
//         for(auto destAndWt : allflights[src]){
//             int dest = destAndWt.first;
//             int wt = destAndWt.second;
//             int findAns = findCheapestPriceHelper(allflights, dest, dst, k-1,dp);
//             ans = min(ans, (double) wt + findAns);
//         }
//         dp[src][dst][k] = ans;
//         return ans;
//     }

//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k ) {
//         unordered_map<int,vector<pair<int,int>>> allflights;
//         for(auto flight : flights){
//             int from = flight[0];
//             int to = flight[1];
//             int cost = flight[2];
//             allflights[from].push_back({to,cost});
//         }

//         vector<vector<vector<double>>> dp(n + 1,vector<vector<double>>(n + 1, vector<double>(k + 1, -100) ));
//         double ans = findCheapestPriceHelper(allflights, src, dst, k, dp);
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
// };