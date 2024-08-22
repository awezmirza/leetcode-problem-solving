class Solution {
public:
    int findComplement(int num) {
        string revBinRepresentation = "";
        while (num) {
            if (num & 1) {
                revBinRepresentation.push_back('0');
            } else {
                revBinRepresentation.push_back('1');
            }

            num >>= 1;
        }

        int n = revBinRepresentation.size();
        int multiplier = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int bit = revBinRepresentation[i] == '1' ? 1 : 0;
            ans += (bit * multiplier);
            multiplier <<= 1;
        }
        return ans;
    }
};