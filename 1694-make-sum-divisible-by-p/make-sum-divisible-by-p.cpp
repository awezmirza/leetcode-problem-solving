class Solution {
public:

    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + nums[i]) % p;
        }
        int target = total % p;
        if (target == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        int curr = 0;
        int ans = n;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int remain = (curr - target + p) % p;
            if (mp.count(remain)) {
                ans = min(ans, i - mp[remain]);
            }
            mp[curr] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};