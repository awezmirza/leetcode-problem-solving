class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sizeOfNew = m * n;
        int orgSize = original.size();
        if (orgSize != sizeOfNew) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                ans[i][j] = original[idx];
            }
        }
        return ans;
    }
};