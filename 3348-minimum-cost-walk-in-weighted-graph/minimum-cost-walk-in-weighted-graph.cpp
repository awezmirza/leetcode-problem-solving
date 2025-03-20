class Solution {
public:

    vector<int> parent;
    vector<int> andOp;
    
    int find(int u) {
        if (parent[u] == u) {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        parent[v] = u;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        andOp.resize(n, -1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parU = find(u);
            int parV = find(v);

            andOp[parU] = andOp[parU] & w & andOp[parV];

            if (parU != parV) {
                unite(parU, parV);
            }
        }
        
        vector<int> ans;

        for (auto que : query) {
            int u = que[0];
            int v = que[1];

            int parU = find(u);
            int parV = find(v);

            if (parU != parV) {
                ans.push_back(-1);
            } else {
                ans.push_back(andOp[parU]);
            }
        }

        return ans;

    }
};