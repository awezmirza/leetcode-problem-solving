class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xored = start ^ goal;
        int count = 0;
        while (xored) {
            if (xored & 1) {
                count++;
            }
            xored /= 2;
        }
        return count;
    }
};