class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        vector<int> zeroesAfterThis(n, 0);
        vector<int> onesBeforeThis(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '1') {
                onesBeforeThis[i] = onesBeforeThis[i - 1] + 1;
            } else {
                onesBeforeThis[i] = onesBeforeThis[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (s[i + 1] == '0') {
                zeroesAfterThis[i] = zeroesAfterThis[i + 1] + 1;
            } else {
                zeroesAfterThis[i] = zeroesAfterThis[i + 1];
            }
        }

        long long oneKBaadZero = 0;
        long long zeroKPhleOne = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneKBaadZero += zeroesAfterThis[i];
            } else {
                zeroKPhleOne += onesBeforeThis[i];
            }
        }

        return min(oneKBaadZero, zeroKPhleOne);
    }
};