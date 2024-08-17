class Solution {
public:

    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n, 0);
        for (int i = 0; i < n; i++) {
            prev[i] = points[0][i];
        }

        for (int i = 1; i < m; i++) {
            vector<long long> curr(n, 0);

            vector<long long> left(n, 0);
            left[0] = prev[0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            vector<long long> right(n, 0);
            right[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            for (int j = 0; j < n; j++) {

                long long prevSum = left[j] + points[i][j];
                long long nextSum = right[j] + points[i][j];
                long long currSum = prev[j] + points[i][j];

                long long maxi = max(prevSum, max(nextSum, currSum));

                curr[j] = maxi;
            }
            prev = curr;

        }

        long long ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, prev[i]);
        }

        return ans;
        
    }
};