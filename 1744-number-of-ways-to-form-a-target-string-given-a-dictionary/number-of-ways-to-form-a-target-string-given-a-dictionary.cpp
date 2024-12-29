class Solution {
    const int MOD = 1000000007;

    int solve(string& target, int i, int t, int& lng, vector<vector<int>>& dp, vector<unordered_map<char, int>>& mp) {
        if (t >= target.size()) {
            return 1;
        }
        if (i >= lng) {
            return 0;
        }

        if (dp[i][t] != -1) {
            return dp[i][t];
        }

        int ans = 0;
        
        char toFind = target[t];
        int totalTargetsOnThisI = mp[i][toFind];

        if (totalTargetsOnThisI > 0) {
            ans = (ans + (1LL * totalTargetsOnThisI * solve(target, i + 1, t + 1, lng, dp, mp)) % MOD) % MOD;
        }
        
        ans = (ans + solve(target, i + 1, t, lng, dp, mp)) % MOD;

        return dp[i][t] = ans;
    }

public:
    int numWays(vector<string>& words, string target) {

        int lng = words[0].size();
        int tgtSz = target.size();
        vector<unordered_map<char, int>> mp(lng);

        for (auto& word : words) {
            for (int i = 0; i < lng; i++) {
                mp[i][word[i]]++;
            }
        }

        vector<vector<int>> dp(lng + 1, vector<int>(tgtSz + 1, -1));

        int ans = solve(target, 0, 0, lng, dp, mp);
        return ans;
    }
};
