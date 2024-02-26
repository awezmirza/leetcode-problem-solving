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

    int helperTab(int m, int n){
        vector<int> temp(n,1);
        for(int x = m - 2;x>=0;x--){
            vector<int> curr(n,1);
            for(int y = n-2;y>=0;y--){
                curr[y] = temp[y] + curr[y + 1];
            }
            temp = curr;
        }
        return temp[0];
    }

    int uniquePaths(int m, int n) {
        int ans = helperTab(m, n);
        return ans;
    }
};