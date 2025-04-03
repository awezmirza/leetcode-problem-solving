class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater(n, 0);
        int prevGreater = nums[0];

        for (int i = n - 2; i >= 0; i--) {
            nextGreater[i] = max(nextGreater[i + 1], nums[i + 1]);
        }

        long long ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (long long) (prevGreater - nums[i]) * nextGreater[i]);
            prevGreater = max(prevGreater, nums[i]);
        }

        return ans;
    }
};