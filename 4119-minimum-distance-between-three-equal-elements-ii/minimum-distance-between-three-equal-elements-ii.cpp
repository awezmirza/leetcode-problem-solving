class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, pair<int, int>> mp;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.count(num)) {
                auto pr = mp[num];
                if (pr.first != -1) {
                    ans = min(ans, abs(i - pr.second) + abs(pr.second - pr.first) + abs(pr.first - i));
                }
                mp[num] = {pr.second, i};
            } else {
                mp[num] = {-1 , i};
            }
        }

        return ans == INT_MAX ? -1 : ans;

    }
};