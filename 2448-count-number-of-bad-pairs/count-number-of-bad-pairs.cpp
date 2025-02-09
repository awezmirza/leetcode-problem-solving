class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long goodPairs = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int val = nums[i] - i;
            goodPairs += mp[val];
            mp[val]++;
        }

        return ((long long) n * (n - 1)) / 2 - goodPairs;
    }
};