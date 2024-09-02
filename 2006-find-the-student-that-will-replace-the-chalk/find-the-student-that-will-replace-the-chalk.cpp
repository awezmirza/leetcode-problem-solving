class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (auto num : chalk) {
            total += (long) num;
        }
        k = k % total;
        int i = 0;
        while (k > 0) {
            k -= chalk[i];
            if (k >= 0) {
                i++;
            }
        }
        return i;
    }
};