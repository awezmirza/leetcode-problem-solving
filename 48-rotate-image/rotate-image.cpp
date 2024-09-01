class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            int lastCol = n - i - 1;
            int left = 0;
            for (int j = i; j < lastCol; j++) {
                swap(matrix[i][j], matrix[i + left][lastCol]);
                swap(matrix[i][j], matrix[lastCol][lastCol - left]);
                swap(matrix[i][j], matrix[lastCol - left][i]);
                left++;
            }
        }
    }
};