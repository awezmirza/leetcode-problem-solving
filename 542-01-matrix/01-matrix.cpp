class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            cnt++;

            for (int it = 0; it < size; it++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Up
                if (row - 1 >= 0 && vis[row - 1][col] != true) {
                    if (mat[row - 1][col] != 0) {
                        ans[row - 1][col] = cnt;
                        vis[row - 1][col] = true;
                        q.push({row - 1, col});
                    }
                }

                // Down
                if (row + 1 < m && vis[row + 1][col] != true) {
                    if (mat[row + 1][col] != 0) {
                        vis[row + 1][col] = true;
                        ans[row + 1][col] = cnt;
                        q.push({row + 1, col});
                    }
                }

                // Left
                if (col - 1 >= 0 && vis[row][col - 1] != true) {
                    if (mat[row][col - 1] != 0) {
                        vis[row][col - 1] = true;                        
                        ans[row][col - 1] = cnt;
                        q.push({row, col - 1});
                    }
                } 

                // Right
                if (col + 1 < n && vis[row][col + 1] != true) {
                    if (mat[row][col + 1] != 0) {
                        vis[row][col + 1] = true;
                        ans[row][col + 1] = cnt;
                        q.push({row, col + 1});
                    }
                }
            }
        }
        
        return ans;
    }
};