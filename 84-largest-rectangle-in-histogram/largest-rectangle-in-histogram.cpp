class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevLowestIdx(n, -1);
        vector<int> nextLowestIdx(n, n);

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            prevLowestIdx[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        st2.push(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st2.top() != n && heights[i] <= heights[st2.top()]) {
                st2.pop();
            }
            nextLowestIdx[i] = st2.top();
            st2.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            cout<<nextLowestIdx[i]<<" ";
            int width = (nextLowestIdx[i] - i) + (i - prevLowestIdx[i]) - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;

    }
};