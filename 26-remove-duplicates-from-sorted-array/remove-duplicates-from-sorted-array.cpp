class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            while (i < n && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i < n) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};