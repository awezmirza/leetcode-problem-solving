class Solution {
public:

    #define INFINITY 10000009

    void floydWarshall(vector<vector<int>>& SPM) {
        int n = SPM.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    SPM[i][j] = min(SPM[i][j], SPM[i][k] + SPM[k][j]);
                }
            }
        }
    }

    int findResultCity(int n, vector<vector<int>>& SPM, int distanceThreshold) {
        int resCity = -1;
        int leastCnt = INFINITY;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && SPM[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= leastCnt) {
                leastCnt = count;
                resCity = i;
            }
        }

        return resCity;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INFINITY));

        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            SPM[u][v] = w;
            SPM[v][u] = w;
        }

        floydWarshall(SPM);

        return findResultCity(n, SPM, distanceThreshold);
    }
};