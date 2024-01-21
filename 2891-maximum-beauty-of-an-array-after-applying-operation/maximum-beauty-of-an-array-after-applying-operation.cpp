class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> mp(200002);
        for(int num:nums){
            if (num - k <= 0) {
                mp[0]++;
            }
            else{
                mp[num - k]++;
            }
            mp[num + k + 1]--;
        }
        int maxi = 0;
        int currSum=0;
        for(int el :mp){
            currSum += el;
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
};