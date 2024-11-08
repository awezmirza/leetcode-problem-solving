class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> cumXor(n, 0);
        cumXor[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumXor[i] = cumXor[i - 1] ^ nums[i];
        }
        reverse(cumXor.begin(), cumXor.end());
        int twoRaceMaxi = (1 << maximumBit) - 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int currAns = cumXor[i] ^ twoRaceMaxi;
            ans[i] = currAns;
        }
        return ans;
    }
};