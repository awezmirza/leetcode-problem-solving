class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int currSum = 0;
        mp[0] = 1;
        int ans = 0;
        for (int num : nums) {
            currSum += num;
            int toFind = currSum - k;
            ans += mp[toFind];
            mp[currSum]++;
        }
        return ans;
    }
};