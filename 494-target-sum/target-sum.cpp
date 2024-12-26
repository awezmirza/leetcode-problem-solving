class Solution {

    int solve(vector<int>& nums, int target, int curr, int idx) {
        int n = nums.size();
        if (idx >= n) {
            if (curr == target) {
                return 1;
            }
            return 0;
        }
        // Without - 
        int without = solve(nums, target, curr + nums[idx], idx + 1);

        // With - 
        int with = solve(nums, target, curr - nums[idx], idx + 1);

        return without + with;
    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(nums, target, 0, 0);
        return ans;
    }
};