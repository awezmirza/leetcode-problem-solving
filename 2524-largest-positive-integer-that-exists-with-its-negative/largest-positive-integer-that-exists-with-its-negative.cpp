class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int st = 0;
        int end = nums.size() - 1;
        while(st < end){
            int ngtve = -1 * nums[st];
            int pstve = nums[end];

            if(ngtve == pstve){
                return pstve;
            }
            else if(ngtve > pstve){
                st++;
            }
            else{
                end--;
            }
        }
        return -1;
    }
};