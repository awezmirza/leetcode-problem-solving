class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        
        if (k > 0) {
            int cumSum = 0;

            for (int i = 0; i < k; i++) {
                cumSum += code[(i + 1) % n];
            }
            
            for (int i = 0; i < n; i++) {
                ans[i] = cumSum;
                cumSum -= code[(i + 1) % n];
                cumSum += code[(i + 1 + k) % n];
            }
        } else if (k < 0) {
            int cumSum = 0;

            for (int i = 1; i <= -(k); i++) {
                int idx = -(i);
                if (idx < 0) {
                    idx += n;
                }
                cumSum += code[idx];
            }
            
            for (int i = 0; i < n; i++) {
                ans[i] = cumSum;
                cumSum += code[i];
                int subIdx = i + k;
                if (subIdx < 0) {
                    subIdx += n;
                }
                cumSum -= code[subIdx];
            }
        }
        return ans;
    }
};