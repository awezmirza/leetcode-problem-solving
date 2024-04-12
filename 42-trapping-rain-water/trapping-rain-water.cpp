class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height.front();
        int rightMax = height.back();
        int leftPtr = 0;
        int rightPtr = height.size() - 1;

        int ans = 0;

        while (leftPtr < rightPtr) {
            if (height[leftPtr] > rightMax){
                rightPtr--;
                if (height[rightPtr] < rightMax){
                    ans += rightMax - height[rightPtr];
                }
                else{
                    rightMax = max(rightMax, height[rightPtr]);
                }
            }
            else{
                leftPtr++;
                if (height[leftPtr] < leftMax){
                    ans += leftMax - height[leftPtr];
                }
                else{
                    leftMax = max(leftMax, height[leftPtr]);
                }
            }
        }

        return ans;
    }
};