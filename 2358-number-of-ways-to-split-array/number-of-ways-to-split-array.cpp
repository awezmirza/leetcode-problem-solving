class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        double backSum = 0;
        for (int i = 0; i < n; i++) {
            backSum += nums[i];
        }

        int ans = 0;
        double cumSum = 0;

        for (int i = 0; i < n - 1; i++) {
            cumSum += nums[i];
            backSum -= nums[i];
            if (cumSum >= backSum) {
                ans++;
            }
        }
        return ans;
    }
};