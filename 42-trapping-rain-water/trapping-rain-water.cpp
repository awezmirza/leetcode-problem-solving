class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prevGreater(n, 0);
        prevGreater[0] = 0;
        int maxi = height[0];
        for (int i = 1; i < n; i++) {
            prevGreater[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        vector<int> nextGreater(n, 0);
        nextGreater[n - 1] = 0;
        maxi = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            nextGreater[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        vector<int> waterLogged(n, 0);
        int ans = waterLogged[0];
        for (int i = 0; i < n; i++) {
            int currHeight = min(prevGreater[i], nextGreater[i]);
            waterLogged[i] = max(0, currHeight - height[i]);
        }

        for (int i = 1; i < n; i++) {
            ans += waterLogged[i];
        }

        return ans;
    }
};