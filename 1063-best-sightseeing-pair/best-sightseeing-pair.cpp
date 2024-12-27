class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), ans = -1, dp = values[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, dp + values[i] - i);
            dp = max(values[i] + i, dp);
        }
        return ans;
    }
};