class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            int dig = columnNumber % 26;
            if (dig == 0) {
                ans.push_back('Z');
                columnNumber--;
            } else {
                ans.push_back(dig - 1 + 'A');
            }
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};