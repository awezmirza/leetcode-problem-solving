class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        int n = nums.size();
        mp[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            int toFind = target - nums[i];
            if (mp.count(toFind)) {
                return {i, mp[toFind]};
            } else {
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};