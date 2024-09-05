class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        // Calculating sum of all values of rolls
        int sumOfAllNums = accumulate(rolls.begin(), rolls.end(), 0);
        
        int m = rolls.size();

        // Calculating sum of ans vector
        int ansVecKaSum = ((mean * (n + m)) - sumOfAllNums);

        // Checking for the not possible values
        if (n > ansVecKaSum || 6 * n < ansVecKaSum) {
            return {};
        }

        // Calculating the number that will be filled in all ans vector
        int toFill = ansVecKaSum / n;

        // Getting the remaining sum after filling the vector with the above value
        int remain = ansVecKaSum % n;

        // Creating and filling ans vector
        vector<int> ans(n, toFill);

        // Filling the remaining value greedily
        for (int i = 0; i < remain; i++) {
            ans[i]++;
        }
        
        return ans;
    }
};