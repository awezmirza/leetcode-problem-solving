class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = m * (1 << (n - 1));

        for(int j = 1; j < n; j++){
            int colCnt = 0;
            for(int i = 0; i < m; i++){
                int curr = grid[i][0] == 1 ? grid[i][j] : grid[i][j] ^ 1;
                colCnt += curr;
            }
            colCnt = max(colCnt, m - colCnt);
            ans += (colCnt * (1 << (n - 1 - j)));
        }
        return ans;
    }
};