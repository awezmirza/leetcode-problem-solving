class Solution {
public:

    void markRowsZero(vector<vector<int>>& matrix, int row, int col) {
        for (int i = 0; i < col; i++) {
            matrix[row][i] = 0;
        }
    }

    void markColsZero(vector<vector<int>>& matrix, int col, int row) {
        for (int i = 0; i < row; i++) {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> cols(202);
        vector<bool> rows(202);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                    markRowsZero(matrix, i, j);
                    markColsZero(matrix, j, i);
                } else if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};