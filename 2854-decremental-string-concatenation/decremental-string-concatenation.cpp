class Solution {
public:
    int solveUsingRecur(vector<string>& words, int i, char& front, char& back, vector<vector<vector<int>>>& dp){
        if(i >= words.size()) return 0;
        int ans = 10000000;
        int size = words[i].size();
        if(dp[i][front - 'a'][back - 'a'] != -1) return dp[i][front - 'a'][back -'a'];

        // Ans Str k right me
        if(back == words[i].front()){
            ans = min(ans, size - 1 + solveUsingRecur(words, i + 1, front, words[i].back(), dp));
        }
        else{
            ans = min(ans, size + solveUsingRecur(words, i + 1, front, words[i].back(), dp));
        }

        // Ans Str k Left me
        if(words[i].back() == front){
            ans = min(ans, size - 1 + solveUsingRecur(words, i + 1, words[i].front(), back, dp));
        }
        else{
            ans = min(ans, size + solveUsingRecur(words, i + 1, words[i].front(), back, dp));
        }

        dp[i][front - 'a'][back - 'a'] = ans;
        return ans;
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>> dp(words.size(),vector<vector<int>> (26, vector<int> (26, -1)));
        int n = words[0].size();
        int ans = n + solveUsingRecur(words, 1, words[0].front(), words[0].back(), dp);
        return ans;
    }
};