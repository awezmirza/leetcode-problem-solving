class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();

        string ans = "";

        int dig = 0;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                dig++;
            } else {
                if (dig > 0) {
                    dig--;
                } else {
                    ans.push_back(ch);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};