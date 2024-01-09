class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> sieve(n+1, true);
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                int ptr = i * i;
                while (ptr <= n) {
                    sieve[ptr] = false;
                    ptr += i;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 2; i < (n / 2) + 1; i++) {
            if (sieve[i] && sieve[n - i]) {
                ans.push_back({i, n - i});
            }
        }
        return ans;
    }
};