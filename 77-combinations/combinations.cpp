class Solution {
public:

    void solve (int num, vector<int>& curr, vector<vector<int>>& ans, int k, int n) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (num > n) {
            return;
        }

        solve(num + 1, curr, ans, k, n);

        curr.push_back(num);
        solve(num + 1, curr, ans, k, n);
        curr.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, curr, ans, k, n);
        return ans;
    }
};