class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> lastRow(cols, 0);
        for(int j = rows - 1;j >= 0;--j){
            vector<int> currRow(cols, 0);
            for(int i = 0;i<cols;i++){
                int miniR = miniR = matrix[j][i] + lastRow[i];
                if(i != cols - 1) miniR = min(miniR, matrix[j][i] + lastRow[i + 1]);
                if(i != 0) miniR = min(miniR, matrix[j][i] + lastRow[i - 1]);
                currRow[i] = miniR;
            }
            lastRow = currRow;
        }
        int mini = INT_MAX;
        for(int i = 0;i<cols;i++){
            mini = min(lastRow[i], mini);
        }
        return mini;
    }
};