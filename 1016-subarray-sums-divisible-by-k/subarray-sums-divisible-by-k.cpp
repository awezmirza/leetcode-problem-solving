class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            int remainder = currSum % k;
            if (remainder < 0) {
                remainder += k;
            }
            ans += mp[remainder];
            mp[remainder]++;
        }
        return ans;
    }
};