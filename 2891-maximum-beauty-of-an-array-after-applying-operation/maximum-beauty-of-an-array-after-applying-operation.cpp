class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> mp(200002);
        int greatestElem = 0;
        for(int num:nums){
            if (num - k <= 0) {
                mp[0]++;
            }
            else{
                mp[num - k]++;
            }
            mp[num + k + 1]--;
            greatestElem = max(greatestElem,num + k + 1);
        }
        int maxi = 0;
        int currSum=0;
        for(int i=0;i<greatestElem;i++){
            currSum += mp[i];
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
};