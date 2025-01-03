class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<double> suffSum(n, 0);

        suffSum[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            suffSum[n - 1 - i] = suffSum[n - i] + nums[n - 1 - i];
        }
        int ans = 0;
        double cumSum = 0;

        for (int i = 0; i < n - 1; i++) {
            cumSum += nums[i];
            if (cumSum >= suffSum[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};