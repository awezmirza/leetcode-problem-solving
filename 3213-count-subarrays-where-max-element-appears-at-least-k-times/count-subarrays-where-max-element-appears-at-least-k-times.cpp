class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1;
        for(int num:nums){
            maxi = max(maxi, num);
        }
        int currCntOfMaxi = 0;
        long long ans = 0;
        int left = 0;
        for(int right = 0;right<n;right++){
            if(nums[right] == maxi) currCntOfMaxi++;
            while(currCntOfMaxi>=k){
                if(nums[left] == maxi) currCntOfMaxi--;
                ans += n - right; 
                left++;
            }
        }
        return ans;
    }
};