class Solution {
public:

    void solve (set<vector<int>>& ansSet, vector<int>& nums, vector<int>& curr, int index) {
        if (index >= nums.size()) {
            ansSet.insert(curr);
            return;
        }

        // Take
        curr.push_back(nums[index]);
        solve(ansSet, nums, curr, index + 1);
        curr.pop_back();

        // Leave
        solve(ansSet, nums, curr, index + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ansSet;
        vector<int> curr = {};
        solve(ansSet, nums, curr, 0);
        return {ansSet.begin(), ansSet.end()};
    }
};