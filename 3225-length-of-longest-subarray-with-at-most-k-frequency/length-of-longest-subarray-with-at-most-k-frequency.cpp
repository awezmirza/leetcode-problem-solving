class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqInTheWindow;
        int numsSize = nums.size();
        int i = 0;
        int ans = 0;
        for (int j = 0; j < numsSize; j++) {
            freqInTheWindow[nums[j]]++;
            while (i <= j && freqInTheWindow[nums[j]] > k) {
                freqInTheWindow[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};