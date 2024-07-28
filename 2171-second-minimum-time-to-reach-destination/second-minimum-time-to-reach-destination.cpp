class Solution {
public:

    #define infi 100000009

    int dijktra(unordered_map<int, vector<int>>& adj, int n, int time, int change) {
        vector<int> currTime(n + 1, infi);
        vector<int> currTime2(n + 1, infi);
        currTime[1] = 0;
        int ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while (!pq.empty()) {
            int frNode = pq.top().second;
            int frCost = pq.top().first;
            pq.pop();

            if (frCost % change != frCost % (2 * change)) {
                frCost += ((2 * change) - (frCost % (2 * change)));
            }

            for (auto nbr : adj[frNode]) {         
                if (frCost + time < currTime[nbr]) {
                    currTime2[nbr] = currTime[nbr];
                    currTime[nbr] = frCost + time;
                    pq.push({frCost + time, nbr});
                } else if (frCost + time < currTime2[nbr] && frCost + time != currTime[nbr]) {
                    currTime2[nbr] = frCost + time;
                    pq.push({frCost + time, nbr});
                }

                if (nbr == n && currTime2[nbr] != infi) {
                    return currTime2[n];
                }
            }
        }

        return currTime2[n];
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int shortestPath = dijktra(adj, n, time, change);

        return shortestPath;
    }
};