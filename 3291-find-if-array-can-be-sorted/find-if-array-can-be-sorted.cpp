class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int currMaxi = INT_MIN, currMin = INT_MAX, prevMaxi = -1;
        int i = 0, n = nums.size();

        while (i < n) {
            int currppCnt = __builtin_popcount(nums[i]);
            while (i < n && currppCnt == __builtin_popcount(nums[i])) {
                currMaxi = max(currMaxi, nums[i]);
                currMin = min(currMin, nums[i]);
                i++;
            }
            if (currMin < prevMaxi) {
                return false;
            }
            prevMaxi = currMaxi;
            currMaxi = INT_MIN;
            currMin = INT_MAX;
        }
        return true;
    }
};