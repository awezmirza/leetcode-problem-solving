class Solution {
public:

    bool isMagicGrid(int row, int col, vector<vector<int>>& grid) {
        
        int sum = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        
        vector<bool> occurrance(10, false);
        for (int i = 0; i < 3; i++) {
            int currRowSum = 0;
            int currColSum = 0;
            for (int j = 0; j < 3; j++) {
                
                if (grid[row + i][col + j] < 10 && occurrance[grid[row + i][col + j]] == true) {
                    return false;
                }
                occurrance[grid[row + i][col + j]] = true;
                currRowSum += grid[row + i][col + j];
                currColSum += grid[row + j][col + i];
            }
            if (currRowSum != sum || currColSum != sum) {
                return false;
            }
        }

        for (int i = 1; i < 10; i++) {
            if (occurrance[i] == false) {
                return false;
            }
        }

        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum || 
           grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2] != sum) {
            return false;
           }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for (int row = 0; row < rows - 2; row++) {
            for (int col = 0; col < cols - 2; col++) {
                if (isMagicGrid(row, col, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};