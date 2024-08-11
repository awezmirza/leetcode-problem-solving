class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lPtr = 0;
        int n = nums.size();
        int rPtr = n - 1;
        int ans = 0;
        while (lPtr < rPtr) {
            if (nums[lPtr] + nums[rPtr] == k) {
                ans++;
                lPtr++;
                rPtr--;
            } else if (nums[lPtr] + nums[rPtr] < k) {
                lPtr++;
            } else {
                rPtr--;
            }
        }
        return ans;
    }
};