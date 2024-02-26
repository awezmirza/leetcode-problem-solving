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
        vector<vector<int>> grid(destx , vector<int> (desty,0));
        for(int i = 0;i<destx;i++){
            grid[i][desty -1] = 1;
        }
        for(int j = 0;j<desty;j++){
            grid[destx-1][j] = 1;
        }
        for(int x = destx - 2;x>=0;x--){
            for(int y = desty-2;y>=0;y--){
                int right = 0;
                if(x != destx - 1) right = grid[x + 1][y];
                int down = 0;
                if(y != desty - 1) down = grid[x][y + 1];
                grid[x][y] = right + down;
            }
        }
        for(auto el:grid){
            for(auto e:el){
                cout<<e<<" ";
            }
            cout<<"\n";
        }
        return grid[0][0];
    }

    int uniquePaths(int m, int n) {
        int ans = helperTab(m, n);
        return ans;
    }
};