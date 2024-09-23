class Solution {
public:
    int solve(int i, string& s, unordered_set<string>& st, int left, vector<vector<int>>& dp) {
        int n = s.size();
        if (i >= n) {
            return left;
        }

        if (dp[i][left] != -1) {
            return dp[i][left];
        } 

        string curr = "";
        int ans = 51;
        int j = i;
        int preLeft = left;
        while (i < n) {
            curr.push_back(s[i]);
            left++;
            i++;
            if (st.count(curr)) {
                ans = min(ans, solve(i, s, st, left - curr.size(), dp));
            } else {
                ans = min(ans, solve(i, s, st, left, dp));
            }
        }
        return dp[j][preLeft] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for (auto word : dictionary) {
            st.insert(word);
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = solve(0, s, st, 0, dp);
        return ans;
    }
};