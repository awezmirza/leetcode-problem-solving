class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prevMax(n), nextMax(n);
        prevMax[0] = height[0];
        nextMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            prevMax[i] = max(height[i], prevMax[i - 1]);
            nextMax[n - 1 - i] = max(height[n - 1 - i], nextMax[n - i]);
        }

        int totalTrapped = 0;
        for (int i = 0; i < n; i++) {
            int currTrapped = min(prevMax[i], nextMax[i]) - height[i];
            totalTrapped += currTrapped;
        }
        return totalTrapped;
    }
};