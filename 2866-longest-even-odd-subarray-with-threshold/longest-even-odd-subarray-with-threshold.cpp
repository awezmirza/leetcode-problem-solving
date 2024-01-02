class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                cnt = 1;

                while (i + 1 < n) {
                    if (nums[i + 1] % 2 == nums[i] % 2 || nums[i+1] > threshold) {
                        break;
                    }
                    ++i, ++cnt;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};