class Solution {
public:

    bool isPal(string s) {
        int st = 0, end = s.size() - 1;
        while (st < end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    void solve(string s, vector<string>& curr, vector<vector<string>>& ans, int i) {
        int n = s.size();
        if (i >= n) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < n; j++) {
            string subStr = s.substr(i, j - i + 1);
            if (isPal(subStr)) {
                curr.push_back(subStr);
                solve(s, curr, ans, j + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, curr, ans, 0);
        return ans;
    }
};