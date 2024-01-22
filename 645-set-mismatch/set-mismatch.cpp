class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = 0;
        vector<int> ans;
        int num = 1;
        for (int el:nums) {
            if(el == num) num++; 
            if (el == prev) ans.push_back(prev); 
            prev = el;
        }
        ans.push_back(num);
        return ans;
    }
};