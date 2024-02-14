class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pstvePtr = 0;
        int ngtvePtr = 1;
        vector<int> ans(n,0);
        for(int num:nums){
            if(num<0){
                ans[ngtvePtr] = num;
                ngtvePtr+= 2;
            } 
            else{
                ans[pstvePtr] = num;
                pstvePtr+= 2;
            }
        }
        return ans;
    }
};