class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int pfSum = 0;
        unordered_map<int,int> mp;
        mp[0] = 0;

        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            pfSum += nums[i] == 1 ? 1 : -1;
            if(mp.count(pfSum)){
                ans = max(ans, i + 1 - mp[pfSum]);
            }
            else{
                mp[pfSum] = i+1;
            }
        }
        return ans;
    }
};