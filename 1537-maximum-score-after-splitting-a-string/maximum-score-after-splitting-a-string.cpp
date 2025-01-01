class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalZeroes = 0;
        int totalOnes = 0;
        for (auto ch : s) {
            if (ch == '0') {
                totalZeroes++;
            } else {
                totalOnes++;
            }
        }

        int ans = 0;

        int zeroesSeen = 0;
        int onesSeen = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                zeroesSeen++;
            } else {
                onesSeen++;
            }

            int onesInRight = totalOnes - onesSeen;
            ans = max(ans, onesInRight + zeroesSeen);
        }
        return ans;
    }
};