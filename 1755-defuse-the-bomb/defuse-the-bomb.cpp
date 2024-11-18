class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += code[(j + i) % n];
                }
                ans[i] = sum;
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -(k); j++) {
                    int idx = i - j;
                    if (idx < 0) {
                        idx += n;
                    }
                    sum += code[idx];
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};