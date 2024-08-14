class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int i = 0;
        int right = n - 1;

        while (left <= right) {
            if (nums[left] == 0) {
                swap(nums[i], nums[left]);
                i++;
                left++;
            } else if (nums[left] == 2) {
                swap(nums[right], nums[left]);
                right--;
            } else {
                left++;
            }
        }
    }
};