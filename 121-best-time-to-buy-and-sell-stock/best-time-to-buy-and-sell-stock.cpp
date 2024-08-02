class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> smallest(n);
        smallest[0] = prices[0];
        for (int i = 1; i < n; i++) {
            smallest[i] = min(smallest[i - 1], prices[i]);
        }
        
        vector<int> greatest(n);
        greatest[n - 1] = prices[n - 1];
       
        for (int i = n - 2; i >= 0; i--) {
            greatest[i] = max(greatest[i + 1], prices[i]);
        }

        int profit = 0;
        for (int i = 0; i < n; i++) {
            profit = max(greatest[i] - smallest[i], profit);
        }

        return profit;
    }
};