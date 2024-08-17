class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return 0;
        }
        int temp = x;
        long long temp2 = 0;
        while (temp) {
            int dig = temp % 10;
            temp2 = temp2 * 10 + dig;
            temp /= 10;
        }
        return x == temp2;
    }
};