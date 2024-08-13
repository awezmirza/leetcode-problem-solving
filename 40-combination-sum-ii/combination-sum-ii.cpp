class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& candidates, int target, int i, vector<int>& curr) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (i >= n || target < 0 || target - candidates[i] < 0) {
            return;
        }

        for (int j = i; j < n; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }

            curr.push_back(candidates[j]);
            solve(ans, candidates, target - candidates[j], j + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, candidates, target, 0, curr);
        return ans;
    }
};