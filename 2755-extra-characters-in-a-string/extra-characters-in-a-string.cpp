class Solution {
public:
    
    int solve(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        int n = s.size();
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }
        
        int ans = n;
        ans = min(ans, 1 + solve(i + 1, s, st, dp));
        string curr = "";
        int preI = i;
        while (i < n) {
            curr.push_back(s[i]);
            i++;
            if (st.count(curr)) {
                ans = min(solve(i, s, st, dp), ans);
            }
        }
        return dp[preI] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for (auto word : dictionary) {
            st.insert(word);
        }
        int n = s.size();
        vector<int> dp(n, -1);

        int ans = solve(0, s, st, dp);
        return ans;
    }
};