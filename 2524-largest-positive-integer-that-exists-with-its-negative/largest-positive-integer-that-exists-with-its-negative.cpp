class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (auto num : nums) {
            mp[num] = true;
        }
        int ans = -1;
        for (auto num : nums) {
            if(num > 0 && mp[-1 * num]){
                ans = max(ans, num);
            }
        }
        return ans;
    }
};