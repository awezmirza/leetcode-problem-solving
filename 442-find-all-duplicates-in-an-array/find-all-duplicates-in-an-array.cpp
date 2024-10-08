class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int n : nums) {
            int idx = abs(n) - 1;
            if (nums[idx] < 0) {
                ans.push_back(idx + 1);
            } else {
                nums[idx] *= -1;
            }
        }
        return ans;
    }
};