class Solution {
public:
    
    void solve(int n, int i, vector<int>& ans) {
        if (i > n) {
            return;
        }
        ans.push_back(i);
        for (int j = 0; j <= 9; j++) {
            solve(n, i * 10 + j, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            solve(n, i, ans);
        }
        return ans;
    }
};