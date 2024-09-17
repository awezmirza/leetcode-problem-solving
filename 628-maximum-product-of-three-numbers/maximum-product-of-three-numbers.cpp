class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m1 = nums[0] * nums[1] * nums[2];
        int m2 = nums[0] * nums[1] * nums[n - 1];
        int m3 = nums[0] * nums[n - 2] * nums[n - 1];
        int m4 = nums[n - 3] * nums[n - 2] * nums[n - 1];
        return max(m1, max(m2, max(m3, m4)));
    }
};