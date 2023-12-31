class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int lSum = 0,n = nums.size(),rSum = 0;
        for(int el : nums){
            rSum += el;
        }
        vector <int> ansArray;
        for(int i = 0;i<n;i++){
            rSum -= nums[i];
            ansArray.push_back( (i*nums[i] - lSum) + rSum - (n-1-i)*nums[i]);
            lSum += nums[i];
        }
        return ansArray;
    }
};