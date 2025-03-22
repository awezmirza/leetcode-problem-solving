class Solution {

    int find(int c, vector<int>& parent) {
        if (parent[c] == c) {
            return c;
        }

        return parent[c] = find(parent[c], parent);
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& comp) {
        int paru = find(u, parent);
        int parv = find(v, parent);
        
        if (paru != parv) {

            int mini = min(paru, parv);
            int maxi = max(paru, parv);

            int compMx = comp[maxi];
            int compMi = comp[mini];

            parent[maxi] = mini;
            comp[mini] += comp[maxi];
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> count(n, 0);
        vector<int> comp(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = min(edge[0], edge[1]);
            int v = max(edge[0], edge[1]);

            count[u]++;
            count[v]++;
            unite(u, v, parent, comp);
        }

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            int par = find(i, parent);
            st.insert(par);
        }

        for (int i = 0; i < n; i++) {
            int par = find(i, parent);
            if (st.count(par)) {
                int compo = comp[par];
                if (count[i] != compo - 1) {
                    st.erase(par);
                }
            }
        }

        return st.size();
    }
};