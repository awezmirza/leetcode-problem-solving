class Solution {
public:

    void permuteHelper(vector<int>& nums,int left,int& right, vector<vector<int>>& ans ){
        if(left == right){
            ans.push_back(nums);
            return;
        }
        for(int i = left;i<=right;i++){
            swap(nums[i],nums[left]);
            permuteHelper(nums,left + 1,right,ans);
            swap(nums[i],nums[left]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        vector<vector<int>> ans;
        permuteHelper(nums,left,right, ans);
        return ans;
    }
};