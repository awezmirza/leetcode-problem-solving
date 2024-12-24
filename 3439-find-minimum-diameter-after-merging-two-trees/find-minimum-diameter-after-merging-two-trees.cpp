class Solution {

    int returnFarthest(unordered_map<int, vector<int>>& mp, int src, bool returnVal) {
        queue<int> q;
        q.push(src);
        int dist = -1;
        int lastVal = src;
        unordered_set<int> vis;
        vis.insert(src);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int fr = q.front();
                q.pop();
                lastVal = fr;
                for (int nbr : mp[fr]) {
                    if (!vis.count(nbr)) {
                        q.push(nbr);
                        vis.insert(nbr);
                    }
                }
            }
            dist++;
        }

        if (returnVal) {
            return lastVal;
        }
        return dist;
    }

    int findDiameter(unordered_map<int, vector<int>>& mp, int rand) {
        // Find the farthest 
        int farthestVal = returnFarthest(mp, rand, true);

        // Find the diam from farthest
        return  returnFarthest(mp, farthestVal, false);
    }


public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> mp1, mp2;
        int rand1 = -1, rand2 = -1;
        for (auto edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            mp1[u].push_back(v);
            mp1[v].push_back(u);
            if (rand1 == -1) {
                rand1 = u;
            }
        }

        for (auto edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            mp2[u].push_back(v);
            mp2[v].push_back(u);
            if (rand2 == -1) {
                rand2 = u;
            }
        }

        int d1 = findDiameter(mp1, rand1);
        cout<<d1<<" ";
        int d2 = findDiameter(mp2, rand2);
        cout<<d2<<" ";

        int maxDiam = max(d1, d2);

        if (d1 % 2 != 0) {
            d1++;
        }
        if (d2 % 2 != 0) {
            d2++;
        }

        return max(((d1 / 2) + (d2 / 2) + 1), maxDiam);
    }
};