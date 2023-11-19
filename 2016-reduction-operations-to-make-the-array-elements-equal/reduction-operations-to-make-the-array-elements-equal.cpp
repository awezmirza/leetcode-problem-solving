class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 1,counter = 0,n = nums.size();i<n;i++){
            if(nums[i] > nums[i-1]) counter++;
            ans += counter;
        }
        return ans;
    }
};