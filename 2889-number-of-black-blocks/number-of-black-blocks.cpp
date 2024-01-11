class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n,
                                       vector<vector<int>>& coordinates) {
        map<pair<int, int>, int> matrix;

        for (auto pairs : coordinates) {

            int r = pairs[0], c = pairs[1];

            if (r - 1 >= 0 && c - 1 >= 0)
                matrix[{r - 1, c - 1}]++;

            if (r - 1 >= 0 && c < n - 1)
                matrix[{r - 1,c}]++;

            if (r < m - 1 && c - 1 >= 0)
                matrix[{r, c - 1}]++;

            if (r < m - 1 && c < n - 1)
                matrix[{r, c}]++;

        }

        vector<long long> ans(5, 0);

        for (auto mp : matrix) {
            ans[mp.second]++;
        }

        long long allSum = ans[1] + ans[2] + ans[3] + ans[4];
        ans[0] = (long long) (m - 1) * (n - 1) - allSum;

        return ans;
    }
};