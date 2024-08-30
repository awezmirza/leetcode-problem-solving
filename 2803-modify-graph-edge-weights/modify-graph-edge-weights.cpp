class Solution {
public:

    int dijktra(int source, int destination, int n, unordered_map<int, vector<pair<int, int>>>& adj) {

        vector<bool> vis(n, false);
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            int cost = pq.top().first;
            int edge = pq.top().second;
            pq.pop();
            if (!vis[edge]) {
                vis[edge] = true;
                for (auto nbr : adj[edge]) {
                    int nbrEdge = nbr.first;
                    int nbrDist = nbr.second;
                    if (nbrDist != -1) {
                        if (cost + nbrDist < dist[nbrEdge]) {
                            dist[nbrEdge] = cost + nbrDist;
                            pq.push({dist[nbrEdge], nbrEdge});
                        }
                    }
                }
            }
        }
        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto edge : edges) {
            if (edge[2] != -1) {
                adj[edge[0]].push_back({edge[1], edge[2]});
                adj[edge[1]].push_back({edge[0], edge[2]});
            }
        }

        int shortestPath = dijktra(source, destination, n, adj);
        if (shortestPath < target) {
            return {};
        }

        bool shortestPathFound = 0;
        if (shortestPath == target) {
            shortestPathFound = true;
        }
        
        for (auto& edge : edges) {
            int& w = edge[2];
            if (w == -1) {
                if (shortestPathFound) {
                    w = 1000000009;
                } else {
                    w = 1;
                    adj[edge[0]].push_back({edge[1], edge[2]});
                    adj[edge[1]].push_back({edge[0], edge[2]});
                    int shortestPath = dijktra(source, destination, n, adj);
                    if (shortestPath <= target) {
                        w += target - shortestPath;
                        shortestPathFound = true;
                    }
                }
            }
        }
        
        if (shortestPathFound) {
            return edges;
        }

        return {};
    }
};