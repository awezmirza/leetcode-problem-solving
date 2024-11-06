class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ppcnt;
        for (int num : nums) {
            ppcnt.push_back(__builtin_popcount(num));
        }
        int prevMaxi = -1;
        int currMaxi = INT_MIN;
        int currMin = INT_MAX;
        int i = 0;

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