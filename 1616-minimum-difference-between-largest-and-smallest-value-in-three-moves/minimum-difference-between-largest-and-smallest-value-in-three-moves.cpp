class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 4) return 0;
        
        // 0 left se 3 right se
        int ans = nums[n - 4] - nums[0];

        // 1 left se 2 right se
        ans = min(ans, nums[n - 3] - nums[1]);

        // 2 left se 1 right se
        ans = min(ans, nums[n - 2] - nums[2]);

        // 3 left se 0 right se
        ans = min(ans, nums[n - 1] - nums[3]);

        return ans;
    }
};