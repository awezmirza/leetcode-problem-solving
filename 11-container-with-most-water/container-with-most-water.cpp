class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftPtr = 0;
        int rightPtr = n - 1;
        int ans = 0;
        while (leftPtr < rightPtr) {
            int minHeight = min(height[leftPtr], height[rightPtr]);
            int len = rightPtr - leftPtr;
            ans = max(ans, len * minHeight);
            if (height[leftPtr] < height[rightPtr]) {
                leftPtr++;
            } else {
                rightPtr--;
            }
        }
        return ans;
    }
};