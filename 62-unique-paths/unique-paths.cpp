class Solution {
public:

    int helper(vector<vector<int>>& grid, int x, int y, int destx, int desty){
        if(x == destx && y == desty) return 1;
        if(grid[x][y] != -1) return grid[x][y];
        int right = 0;
        if(x != destx) right = helper(grid, x + 1, y, destx, desty);
        int down = 0;
        if(y != desty) down = helper(grid, x, y + 1, destx, desty);
        return grid[x][y] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n,-1));
        int ans = helper(grid, 0, 0, m-1, n-1);
        return ans;
    }
};