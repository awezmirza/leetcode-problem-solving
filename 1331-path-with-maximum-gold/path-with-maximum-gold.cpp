class Solution {
public:

    int backtrack(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }
        int curr = grid[i][j];
        grid[i][j] = 0;

        // Left
        int ans = curr + backtrack(grid, i , j - 1);

        // Up
        ans = max(ans, curr + backtrack(grid, i - 1 , j));

        // Right
        ans = max(ans, curr + backtrack(grid, i , j + 1));

        // Down
        ans = max(ans, curr + backtrack(grid, i + 1 , j));

        grid[i][j] = curr;
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    int btAns = backtrack(grid, i , j);
                    ans = max(ans, btAns);
                }
            }
        }
        return ans;
    }
};