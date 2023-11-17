class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = nums[0] + nums[n-1];
        int its = n>>1;
        for(int i = 1; i<its;i++ ){
            if(nums[i] + nums[n -1- i] > maxi) maxi = nums[i] + nums[n -1- i];
        }
        return maxi;
    }
};