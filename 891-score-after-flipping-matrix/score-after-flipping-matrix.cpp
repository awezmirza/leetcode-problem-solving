class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    grid[i][j] ^= 1;
                }
            }
        }

        for(int j = 1; j < n; j++){
            int colCnt = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 1){
                    colCnt++;
                }
            }
            if(colCnt < m - colCnt){
                for(int i = 0; i < m; i++){
                    grid[i][j] ^= 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){            
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += (1 << (n - 1 - j));
                }
            }
        }
        return ans;
    }
};