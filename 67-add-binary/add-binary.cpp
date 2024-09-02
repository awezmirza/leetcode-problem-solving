class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int aPtr = a.size() - 1;
        int bPtr = b.size() - 1;
        bool carry = false;
        while (aPtr >= 0 || bPtr >= 0 || carry) {
            int curr = carry;
            if (aPtr >= 0) {
                if (a[aPtr] == '1') {
                    curr += 1;
                }
                aPtr--;
            }
            if (bPtr >= 0) {
                if (b[bPtr] == '1') {
                    curr += 1;
                }
                bPtr--;
            }
            if (curr == 0) {
                carry = false;
                ans.push_back('0');
            } else if (curr == 1) {
                carry = false;
                ans.push_back('1');
            } else if (curr == 2) {
                carry = true;
                ans.push_back('0');
            } else {
                carry = true;
                ans.push_back('1');
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};