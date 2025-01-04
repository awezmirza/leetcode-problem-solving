class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if (first[idx] == -1) {
                first[idx] = i;
            } else {
                last[idx] = i;
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