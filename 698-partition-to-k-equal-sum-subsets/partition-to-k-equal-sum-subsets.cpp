class Solution {
public:

    bool solve(vector<int>& nums, int k, int i, int target, int sum, vector<bool> vis) {
        if (k == 0) {
            return true;
        } 
        if (sum == target) {
            return solve(nums, k - 1, 0, target, 0, vis);
        }
        // if (i >= nums.size()) {
        //     return false;
        // }

        for (int j = i; j < nums.size(); j++) {
            if (vis[j] != true && nums[j] + sum <= target) {
                // if (j == i || nums[j] != nums[j - 1]) {
                    vis[j] = true;
                    if (solve(nums, k, j + 1, target, sum + nums[j], vis)) {
                        return true;
                    }
                    vis[j] = false;
                    if (sum == 0) {
                        return false;
                    }
                // }
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % k != 0) {
            return false;
        }

        int targetSum = sum / k;
        
        vector<bool> vis(n);
        return solve(nums, k, 0, targetSum, 0, vis);
    }
};