class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int totalElems = m*n;
        k = k % totalElems;
        int x = k/m;
        int y = k%m;

        vector<vector<int>> ans(n, vector <int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){   
                ans[x][y] = grid[i][j];
                if(y == m-1){
                    y=0;
                    if(x == n-1){
                    x = 0;
                    }
                    else{
                    x++;    
                    }   
                }
                else{
                y++;
                }
            }
        }
        return ans;
    }
};