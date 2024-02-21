class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
         
        vector<long long> copy(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') copy[i] = (long long) nums[i] + d;
            else copy[i] = (long long) nums[i] - d;
        }
        sort(copy.begin(), copy.end());
        long long ans = 0;
        vector<long long> pref(n);
        pref[0] = copy[0];
        for (int i = 1; i < n; i++){
            pref[i] = pref[i-1] + copy[i]; 
        }
        for (int i = 1; i < n; i++){
            ans += (i* (long long)copy[i]) - pref[i-1];
            ans %= (long long)1e9+7;
        }
        return ans;
    }
};