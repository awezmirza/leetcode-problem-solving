class Solution {
    int countSubset(vector<int>& nums, int& maxiSubset, int i, int subset) {
        if (i >= nums.size()) {
            if (subset == maxiSubset) {
                return 1;
            }

            return 0;
        }

        int take = countSubset(nums, maxiSubset, i + 1, subset | nums[i]);
        int notTake = countSubset(nums, maxiSubset, i + 1, subset);

        return take + notTake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxiSubset = 0;
        for (int num : nums) {
            maxiSubset = maxiSubset | num;
        }

        int ans = countSubset(nums, maxiSubset, 0, 0);

        return ans;
    }
};