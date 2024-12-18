class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && prices[j] > prices[i]) {
                j++;
            }
            if (j == n) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - prices[j];
            }
        }
        return ans;
    }
};