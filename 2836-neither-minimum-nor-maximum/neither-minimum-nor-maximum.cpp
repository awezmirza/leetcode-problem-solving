class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return -1;
        int maxi = 0;
        int mini = 101;
        for(auto num:nums){
            if(num < mini) mini = num;
            if(num > maxi) maxi = num;
        }
        for(int i = 0;i<3;i++){
            if(nums[i] != maxi && nums[i] != mini) return nums[i];
        }
        return -1;
    }
};