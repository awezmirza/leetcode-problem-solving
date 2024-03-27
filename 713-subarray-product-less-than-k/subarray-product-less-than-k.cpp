class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int prod = 1;
        int ans = 0;
        for(int j=0;j<n;j++){
            prod *= nums[j];
            while(prod >= k && i<=j){
                prod/= nums[i];
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};