class Solution {

    void dijktras(unordered_map<int, vector<pair<int, int>>>& mp, vector<pair<long long, long long>>& shortest) {
        // Time, Node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int tp = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();

            for (auto& nbr : mp[tp]) {
                if (wt + nbr.second < shortest[nbr.first].first) {
                    shortest[nbr.first] = {wt + nbr.second, shortest[tp].second};
                    pq.push({wt + nbr.second , nbr.first});
                } else if (wt + nbr.second == shortest[nbr.first].first) {
                    shortest[nbr.first].second = (shortest[nbr.first].second + shortest[tp].second) % 1000000007;
                }
            }
        }
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }

        // Shortest dist, incoming
        vector<pair<long long, long long>> shortest(n, {LLONG_MAX, 0});
        shortest[0] = {0, 1};

        dijktras(mp, shortest);

        return shortest[n - 1].second;
    }
};