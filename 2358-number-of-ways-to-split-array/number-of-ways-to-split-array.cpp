class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<double> prefSum(n, 0);
        vector<double> suffSum(n, 0);

        prefSum[0] = nums[0];
        suffSum[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
            suffSum[n - 1 - i] = suffSum[n - i] + nums[n - 1 - i];
        }
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prefSum[i] >= suffSum[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};