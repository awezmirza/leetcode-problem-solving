class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> minInRow;

        for (auto row : matrix) {
            int mini = row[0];
            for (int num : row) {
                mini = min(mini, num);
            }
            minInRow.push_back(mini);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int maxi = matrix[0][i];
            int maxiRow = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] > maxi) {
                    maxi = matrix[j][i];
                    maxiRow = j;
                }
            }
            if (minInRow[maxiRow] == maxi) {
                ans.push_back(minInRow[maxiRow]);
            }
        }

        return ans;
    }
};