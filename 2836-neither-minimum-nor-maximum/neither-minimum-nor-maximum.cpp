class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3) return -1;
        int maxi = max(nums[0],max(nums[1], nums[2]));
        int mini =  min(nums[0],min(nums[1], nums[2]));

        if(nums[0] != maxi && nums[0] != mini) return nums[0];
        else if(nums[1] != maxi && nums[1] != mini) return nums[1];
        else return nums[2];
    }
};
