class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0) return false;

        vector<vector <int>> mp(n*n,vector<int>(2));
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]][0] = i;
                mp[grid[i][j]][1] = j;
            }
        }

        for(int i = 1;i<n*n;i++){

            int row = abs(mp[i][0] - mp[i-1][0]);
            int col = abs(mp[i][1] - mp[i-1][1]);

            if(!(row == 2 && col == 1  || row == 1 && col == 2 )) return false;
        }
        return true;
    }
};