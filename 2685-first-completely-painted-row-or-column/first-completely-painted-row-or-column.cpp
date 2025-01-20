class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;

        int n = mat.size();
        int m = mat[0].size();
        vector<int> col(m);
        vector<int> row(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                int val = mat[i][j];

                mp[val] = {i, j};
            }
        }

        int l = arr.size();

        for (int i = 0; i < l; i++) {
            int val = arr[i];

            int rowIdx = mp[val].first;
            int colIdx = mp[val].second;

            row[rowIdx]++;
            col[colIdx]++;

            if (row[rowIdx] == m || col[colIdx] == n) {
                return i;
            }
        }

        return -1;
    }
};