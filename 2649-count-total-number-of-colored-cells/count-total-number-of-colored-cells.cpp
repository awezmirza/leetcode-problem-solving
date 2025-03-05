class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        int curr = 1;
        for (int i = 1; i < n; i++) {
            ans += curr;
            curr += 2;
        }

        ans *= 2;
        ans += curr;

        return ans;
    }
};