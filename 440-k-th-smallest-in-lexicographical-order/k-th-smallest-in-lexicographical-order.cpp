class Solution {
public:

    int solve(int n, long curr, long next) {
        int count = 0;
        while (curr <= n) {
            count += next - curr;
            next *= 10;
            curr *= 10;
            next = min(next, (long) n + 1);
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int next = curr + 1;
            int count = solve(n, curr, next);
            if (k < count) {
                curr *= 10;
                k--;
            } else {
                k-= count;
                curr++;
            }
        }
        return curr;
    }
};