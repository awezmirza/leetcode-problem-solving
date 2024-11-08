class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int cumXor = 0;
        for (int i = 0; i < n; i++) {
            cumXor ^= nums[i];
        }
        int twoRaceMaxi = (1 << maximumBit) - 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = cumXor ^ twoRaceMaxi;
            cumXor ^= nums[n - i - 1];
        }
        return ans;
    }
};