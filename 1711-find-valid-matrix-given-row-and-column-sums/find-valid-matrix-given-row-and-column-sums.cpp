class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int> (n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mini = min(rowSum[i], colSum[j]);
                ans[i][j] = mini;
                rowSum[i] -= mini;
                colSum[j] -= mini;
            }
        }

        return ans;
    }
};