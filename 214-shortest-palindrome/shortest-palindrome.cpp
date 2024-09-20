class Solution {
public:

    void fillLPS(string s, int n, vector<int>& LPS) {
        int m = s.size();
        int length = 0;
        int i = 1;
        while (i < m) {
            if (s[i] == s[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length == 0) {
                    i++;
                } else {
                    length = LPS[length - 1];
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<int> LPS(n + n + 1, 0);
        fillLPS(s + "-" + rev, n, LPS);
        int last = LPS.back();

        return rev.substr(0, n - last) + s;
    }
};