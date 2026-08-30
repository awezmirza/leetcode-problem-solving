// 3 Possibilities 
// - Remove both from front
// - Remove both from end
// - Remove one from end and other from front

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int miniIdx = 0, maxiIdx = 0;

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[miniIdx]) {
                miniIdx = i;
            } else if (nums[i] > nums[maxiIdx]) {
                maxiIdx = i;
            }
        }

        int fromFront = max(miniIdx, maxiIdx) + 1;
        int fromBack = n - min(miniIdx, maxiIdx);
        int oneByOne = (min(miniIdx, maxiIdx) + 1) + (n - max(miniIdx, maxiIdx));

        return min(fromFront, min(fromBack, oneByOne));
    }
};