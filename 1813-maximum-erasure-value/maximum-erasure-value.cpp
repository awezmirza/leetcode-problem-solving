class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;

        int ans = 0;

        int n = nums.size();
        vector<int> prefSum(n);
        int r = 0;

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            if (mp.contains(num)) {
                r = max(r, mp[num] + 1);
            }
            mp[num] = i;
            if (i == 0) {
                prefSum[i] = num;
                ans = num;
            } else {
                prefSum[i] = prefSum[i - 1] + num;
                if (r == 0) {
                    ans = max(ans, prefSum[i]);
                } else {
                    ans = max(ans, prefSum[i] - prefSum[r - 1]);
                }
            }


            cout<<ans<<" ";
        }

        return ans;
    }
};