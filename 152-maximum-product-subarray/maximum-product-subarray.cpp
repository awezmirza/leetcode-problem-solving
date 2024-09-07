class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int mul = 1;

        for (int i = 0; i < n; i++) {
            if (mul == 0) {
                mul = 1;
            }
            mul *= nums[i];
            ans = max(ans, mul);
        }

        mul = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (mul == 0) {
                mul = 1;
            }
            mul *= nums[i];
            ans = max(ans, mul);
        }

        return ans;
    }
};