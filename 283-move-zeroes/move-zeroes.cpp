class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr1 = 0;
        int n = nums.size();
        int ptr2 = 0;
        while (ptr2 < n) {
            if (nums[ptr2] != 0) {
                swap(nums[ptr1], nums[ptr2]);
                while (ptr1 < n && nums[ptr1] != 0) {
                    ptr1++;
                }
                ptr2 = ptr1 + 1;
            } else {
                ptr2++;
            }
        }
    }
};