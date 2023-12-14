class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rows(m);
    vector<int> cols(n);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] == 1){
                rows[i]++;
                cols[j]++;
            }
        }
    }
    vector<vector<int>> ans(m,vector<int> (n,0));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            int zerosRow = m - rows[i];
            int zerosCol = n - cols[j];
            ans[i][j] = rows[i] + cols[j] - (zerosRow) - (zerosCol);
        }
    }
    return ans;
    }
};