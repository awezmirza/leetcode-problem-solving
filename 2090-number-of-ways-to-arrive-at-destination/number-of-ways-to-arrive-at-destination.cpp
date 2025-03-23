class Solution {

    void dijktras(unordered_map<int, vector<pair<int, int>>>& mp, vector<long long>& dist, vector<int>& ways) {
        // Time, Node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int tp = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();

            // if (wt > dist[tp]) {
            //     continue;
            // } 

            for (auto& [node, time] : mp[tp]) {
                if (wt + time < dist[node]) {
                    dist[node] = (long long)wt + time;
                    ways[node] = ways[tp];
                    pq.push({(long long)wt + time, node});
                } else if ((long long)wt + time == dist[node]) {
                    ways[node] = (ways[node] + ways[tp]) % 1000000007;
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

        // Shortest dist, incoming
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        dijktras(mp, dist, ways);

        return ways[n - 1];
    }
};