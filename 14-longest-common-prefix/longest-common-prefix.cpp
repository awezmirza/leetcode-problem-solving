class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        string ans = "";
        for (int i = 0; i < m; i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }
            ans.push_back(c);
        }

        return ans;
    }
};