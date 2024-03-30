class Solution {
public:
    int solver(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            while(mp.size() > k && j<=i){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            ans += i-j+1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solver(nums, k) - solver(nums, k-1);
    }
};