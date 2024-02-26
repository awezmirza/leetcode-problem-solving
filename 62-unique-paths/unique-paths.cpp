class Solution {
public:

    // int helper(vector<vector<int>>& grid, int x, int y, int destx, int desty){
    //     if(x == destx && y == desty) return 1;
    //     if(grid[x][y] != -1) return grid[x][y];
    //     int right = 0;
    //     if(x != destx) right = helper(grid, x + 1, y, destx, desty);
    //     int down = 0;
    //     if(y != desty) down = helper(grid, x, y + 1, destx, desty);
    //     return grid[x][y] = right + down;
    // }

    int helperTab(int destx, int desty){
        vector<vector<int>> grid(destx , vector<int> (desty,1));
        for(int x = destx - 2;x>=0;x--){
            for(int y = desty-2;y>=0;y--){
                grid[x][y] = grid[x + 1][y] + grid[x][y + 1];
            }
        }
        return grid[0][0];
    }

    int uniquePaths(int m, int n) {
        int ans = helperTab(m, n);
        return ans;
    }
};