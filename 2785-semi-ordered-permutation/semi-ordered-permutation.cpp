class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==1 && nums[n-1]==n) return 0;
        int onesIndex = -1;
        int nsIndex = -1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                onesIndex = i;
            }
            if(nums[i] == n){
                nsIndex = i;
            }
        }
        if(onesIndex < nsIndex){
            ans += onesIndex;
            ans += (n-1 - nsIndex);
            return ans;
        }
        ans += onesIndex;
        ans += (n-2 - nsIndex);
        return ans;
    }
};