class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // if (nums[0] != 1)
        //     return {2, 1};
        int prev = 0;
        vector<int> ans;
        int num = 1;
        for (int i = 0; i < n; i++) {
            if(nums[i] == num){
                num++;
            }
            if (nums[i] == prev) {
                ans.push_back(prev);
            }
            prev = nums[i];
        }
        ans.push_back(num);
        return ans;
    }
};