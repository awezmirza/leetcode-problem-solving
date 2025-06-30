class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int ans = 0;

        for (int num : nums) {
            if (mp[num + 1]) {
                ans = max(ans, mp[num] + mp[num + 1]);
            }
        }

        return ans;

    }
};