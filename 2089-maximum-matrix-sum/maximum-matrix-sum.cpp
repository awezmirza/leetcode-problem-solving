class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int totalNgtve = 0;
        int minEl = 1000009;
        for (auto row : matrix) {
            for (int el : row) {
                if (el < 0) {
                    totalNgtve++;
                }
                minEl = min(minEl, abs(el));
                sum += abs(el);
            }
        }

        if (totalNgtve % 2 != 0) {
            return sum - 2 * minEl;
        }

        return sum;
    }
};