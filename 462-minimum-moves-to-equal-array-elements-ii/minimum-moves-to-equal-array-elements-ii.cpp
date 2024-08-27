class Solution {
public:

    int findMedian(vector<int>& nums) {
        int size = nums.size();
        if (size % 2 == 0) {
            int mid1 = size / 2;
            int mid2 = mid1 - 1;
            return (nums[mid1] + nums[mid2]) / 2;
        }
        return nums[size / 2];
    }

    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = findMedian(nums);
        int ans = 0;
        for (int num : nums) {
            ans += abs(num - median);
        }
        return ans;
    }
};