class Solution {
    
    int MOD = 1000000007;

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> power(n, 0);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int ans = 0;
        int j = n - 1;

        for (int i = 0; i <= min(j, n - 1); i++) {
            while (j >= i && nums[i] + nums[j] > target) {
                j--;
            }
            if (j >= i) {
                ans = (ans + (power[j - i])) % MOD;
            }
        }

        return ans;
    }
};