class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> numCnt(n);
        for(int num:nums){
            numCnt[num] = true;
        }
        for(int i = 0;i<n;i++){
            if(!numCnt[i]) return i;
        }
        return n;
    }
};