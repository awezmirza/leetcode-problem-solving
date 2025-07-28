class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;
        int l = 0, r = 0;
        int n = s.size();

        int ans = 0;

        while (r < n) {

            if (s[r] == 'a') {
                a++;
            } else if (s[r] == 'b') {
                b++;
            } else {
                c++;
            }

            while (a > 0 && b > 0 && c > 0) {

                if (s[l] == 'a') {
                    a--;
                } else if (s[l] == 'b') {
                    b--;
                } else {
                    c--;
                }
                ans += (n - r);
                l++;
            }

            r++;
        }

        return ans;
    }
};