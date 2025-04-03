class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n, 0), nextGreater(n, 0);
        for (int i = 1; i < n; i++) {
            prevGreater[i] = max(prevGreater[i - 1], nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            nextGreater[i] = max(nextGreater[i + 1], nums[i + 1]);
        }

        long long ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, 
            (long long) (prevGreater[i] - nums[i]) * nextGreater[i]
            );
        }

        return ans;
    }
};