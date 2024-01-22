class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dupl = 0;
        for(int el:nums){
            if(nums[abs(el) - 1] < 0){
                dupl = abs(el);
            }
            else{
                nums[abs(el)-1] *= -1; 
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] >0 ){
                return {dupl,i+1};
            }
        }
        return {0,0};
    }
};