class Solution {
public:
    string solve(int n) {
        if (n == 1) {
            return "0";
        }
        string returned = solve(n - 1);
        string inverted = returned;
        int sz = inverted.size();
        for (int i = 0; i < sz; i++) {
            inverted[i] = inverted[i] == '0' ? '1' : '0';
        }
        reverse(inverted.begin(), inverted.end());
        return returned + "1" + inverted;
    }

    char findKthBit(int n, int k) {
        string ans = solve(n);
        return ans[k - 1];
    }
};