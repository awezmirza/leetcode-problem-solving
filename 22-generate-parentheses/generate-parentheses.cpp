class Solution {
public:

    void solve (vector<string>& ans, int open, int close, int n, string currStr) {
        if (open == n && close == n) {
            ans.push_back(currStr);
            return;
        }

        if (close < open) {
            currStr.push_back(')');
            solve(ans, open, close + 1, n, currStr);
            currStr.pop_back();
        }
        if (open < n) {
            currStr.push_back('(');
            solve(ans, open + 1, close, n, currStr);
            currStr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> ans;
        string currStr = "";
        solve(ans, open, close, n, currStr);
        return ans;
    }
};