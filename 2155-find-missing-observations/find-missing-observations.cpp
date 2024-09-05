class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumOfAllNums = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int ansVecKaSum = ((mean * (n + m)) - sumOfAllNums);
        if (n > ansVecKaSum || 6 * n < ansVecKaSum) {
            return {};
        }
        int toFill = ansVecKaSum / n;
        int remain = ansVecKaSum % n;
        vector<int> ans(n, toFill);
        for (int i = 0; i < remain; i++) {
            ans[i]++;
        }
        return ans;
    }
};