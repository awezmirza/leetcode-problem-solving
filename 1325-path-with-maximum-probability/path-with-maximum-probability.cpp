class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        int i = 0;
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], succProb[i]});
            adj[edge[1]].push_back({edge[0], succProb[i]});
            i++;
        }
        vector<double> ans(n, 0);
        ans[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while (!pq.empty()) {
            int topNode = pq.top().second;
            double topProbability = pq.top().first;
            cout<<topNode<<" ";
            pq.pop();

            for (auto nbr : adj[topNode]) {
                int nbrNode = nbr.first;
                double nbrProb = nbr.second;
                if (topProbability * nbrProb > ans[nbrNode]) {
                    ans[nbrNode] = topProbability * nbrProb;
                    pq.push({ans[nbrNode], nbrNode});
                }
            }
        }
        return ans[end_node];
    }
};