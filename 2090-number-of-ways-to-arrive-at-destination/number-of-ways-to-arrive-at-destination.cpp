class Solution {

    typedef pair<long long, int> P;
    const int MOD = 1e9 + 7;

    void dijktras(unordered_map<int, vector<pair<int, int>>>& mp, vector<long long>& dist, vector<int>& ways) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [wt, tp] = pq.top();
            pq.pop();

            for (auto& [node, time] : mp[tp]) {
                if (wt + time < dist[node]) {
                    dist[node] = wt + time;
                    ways[node] = ways[tp];
                    pq.push({wt + time, node});
                } else if (wt + time == dist[node]) {
                    ways[node] = (ways[node] + ways[tp]) % MOD;
                }
            }
        }
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Node, Time
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        dijktras(mp, dist, ways);

        return ways[n - 1];
    }
};