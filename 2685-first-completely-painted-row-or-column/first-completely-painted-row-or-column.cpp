class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;

        int n = mat.size();
        int m = mat[0].size();
        vector<unordered_set<int>> col(m);
        vector<unordered_set<int>> row(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                int val = mat[i][j];

                mp[val] = {i, j};

                row[i].insert(val);
                col[j].insert(val);
            }
        }

        int l = arr.size();

        for (int i = 0; i < l; i++) {
            int val = arr[i];

            int rowIdx = mp[val].first;
            int colIdx = mp[val].second;

            row[rowIdx].erase(val);
            col[colIdx].erase(val);

            if (row[rowIdx].size() == 0 || col[colIdx].size() == 0) {
                return i;
            }
        }

        return -1;
    }
};