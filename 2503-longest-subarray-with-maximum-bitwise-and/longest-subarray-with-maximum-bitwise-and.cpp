class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int largestInt = *max_element(nums.begin(), nums.end());
        int longestSubarray = 0;
        int ans = 1;
        for (int num : nums) {
            if (num == largestInt) {
                longestSubarray++;
            } else {
                longestSubarray = 0;
            }
            ans = max(ans, longestSubarray);
        }        
        return ans;
    }
};