class Solution {
public:

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[right] != s[left]) {
                return false;
            }
            right--, left++;
        }
        return true;
    }
 
    bool validPalindrome(string s) {
        bool deleted = false;
        int left = 0;
        int n = s.size();
        int right = n - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                
            } else {
                if (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1)) {
                    return true;
                }
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};