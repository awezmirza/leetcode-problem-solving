class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        int n = num.size();
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                ans = max(ans, num[i] - '0');
            }
        }

        if (ans == -1) {
            return "";
        }

        char an = ans + '0';

        string a = "";
        a += an;
        a += an;
        a += an;

        return a;
    }
};