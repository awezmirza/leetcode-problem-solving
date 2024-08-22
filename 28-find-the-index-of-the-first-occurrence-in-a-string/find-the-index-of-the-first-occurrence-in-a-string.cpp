class Solution {
public:

    bool match(string haystack, string needle, int i) {
        int n = haystack.size();
        int m = needle.size();
        for (int j = 0; j < m; j++) {
            if (haystack[j + i] != needle[j]) {
                return false;
            }
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; i++) {
            if (haystack[i] == needle[0]) {
                if(match(haystack, needle, i)) {
                    return i;
                }
            }
        }
        return -1;
    }
};