class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();
        vector<int> unique(n, 0);
        unique[0] = 1;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (i != 0) {
                if (first[c - 'a'] == -1) {
                    unique[i] = unique[i - 1] + 1;
                } else {
                    unique[i] = unique[i - 1];
                }
            }

            if (first[c - 'a'] == -1) {
                first[c - 'a'] = i;
            } else {
                last[c - 'a'] = i;
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (last[i] != -1) {
                int frst = first[i];
                int lst = last[i];

                unordered_set<char> st;

                for (int j = frst + 1; j < lst; j++) {
                    st.insert(s[j]);
                }

                ans += st.size();
            }
        }

        return ans;
    }
};