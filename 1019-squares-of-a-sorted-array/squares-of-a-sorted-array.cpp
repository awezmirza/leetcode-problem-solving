class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n-1;
        int ptr = n-1;
        while(left<=right){
            if(abs(nums[left]) <= abs(nums[right])){
                ans[ptr] = nums[right]*nums[right];
                right--;
            }
            else{
                ans[ptr] = nums[left]*nums[left];
                left++;
            }
            ptr--;
        }
        return ans;
    }
};