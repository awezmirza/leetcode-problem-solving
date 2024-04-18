class Solution {
public:
    int findPerimeter(vector<vector<int>>& grid, int i, int j){

        int m = grid.size();
        int n = grid[0].size();

        int currPerim = 0;

        grid[i][j] = -1;

        if(i > 0 && grid[i - 1][j] == 1){
            currPerim += findPerimeter(grid, i - 1, j);
        }
        else if(i == 0 || grid[i - 1][j] == 0){
            currPerim++;
        }


        if(i < m - 1 && grid[i + 1][j] == 1){
            currPerim += findPerimeter(grid, i + 1, j);
        }
        else if(i == m - 1 || grid[i + 1][j] == 0){
            currPerim++;
        }

        if(j > 0 && grid[i][j - 1] == 1){
            currPerim += findPerimeter(grid, i, j - 1);
        }
        else if(j == 0 || grid[i][j - 1] == 0){
            currPerim++;
        }

        if(j < n - 1 && grid[i][j + 1] == 1){
            currPerim += findPerimeter(grid, i, j + 1);
        }
        else if(j == n - 1 || grid[i][j + 1] == 0){
            currPerim++;
        }

        return currPerim;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i = 0;
        int j = 0;

        while(grid[i][j] != 1){
            j++;
            if(j >= n){
                i++;
                j = 0;
            }
        }

        int perimeter = findPerimeter(grid, i, j);

        return perimeter;
    }
};