class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            char ch = s[i];
            if (st.empty()) {
                st.push(ch);
            } 
            else {
                char stTop = st.top();
                bool isUpperCase = stTop - 'A' < 26 ? true : false;
                bool isSame = false;
                if (isUpperCase) {
                    char convertingToLowerCase = stTop + 'a' - 'A';
                    if (convertingToLowerCase == ch) {
                        isSame = true;
                    }
                } else {
                    char convertingToUpperCase = stTop - ('a' - 'A');
                    if (convertingToUpperCase == ch) {
                        isSame = true;
                    }
                }
                if (!isSame) {
                    st.push(ch);
                } else {
                    st.pop();
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};