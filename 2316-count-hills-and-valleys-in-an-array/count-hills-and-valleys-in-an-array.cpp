class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            int left = 0;
            int l = i - 1;

            if (nums[l] == nums[i]) {
                continue;
            }

            while (l >= 0 && nums[l] == nums[i]) {
                l--;
            }

            if (l == -1) {
                continue;
            }

            if (nums[l] < nums[i]) {
                left = -1;
            } else {
                left = 1;
            }

            int right = 0;
            int r = i + 1;

            while (r < n && nums[r] == nums[i]) {
                r++;
            }

            if (r == n) {
                continue;
            }

            if (nums[r] < nums[i]) {
                right = -1;
            } else {
                right = 1;
            }

            if (left == right) {
                ans++;
            }

        }

        return ans;
    }
};