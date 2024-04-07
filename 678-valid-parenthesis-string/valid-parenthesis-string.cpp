class Solution {
public:
    bool solve(int openCnt, int index, string s, vector<vector<int>>& dp){
        while(index < s.size() && s[index] != '*'){
            if(s[index] == '('){
                openCnt++;
            }
            else{
                if(openCnt <= 0){
                    return false;
                }
                openCnt--;
            }
            index++;
        }
        if(index >= s.size()){
            if(openCnt) return false;
            return true;
        }
        if(dp[openCnt][index]!= -1){
            return dp[openCnt][index];
        }
        bool isValid = solve(openCnt + 1, index + 1, s, dp);
        if(openCnt > 0){
            isValid = isValid || solve(openCnt - 1, index + 1, s, dp);
        }
        isValid = isValid || solve(openCnt , index + 1, s, dp);
        return dp[openCnt][index] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, s, dp);
    }
};