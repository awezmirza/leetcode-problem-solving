class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(n - 1);
        ans[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - prices[st.top()];
            }
            st.push(i);
        }

        return ans;
    }
};