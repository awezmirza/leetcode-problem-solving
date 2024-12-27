class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = -1;
        int dp = values[0];
   
        for (int i = 1; i < n; i++) {
            ans = max(ans, dp + values[i] - i);
            dp = max(values[i] + i, dp);
        }
        return ans;
    }
};