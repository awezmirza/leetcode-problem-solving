class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int currMul = nums[i];
            ans = max(ans, currMul);
            for (int j = i + 1; j < n; j++) {
                currMul *= nums[j];
                ans = max(ans, currMul);
            }
        }
        return ans;
    }
};