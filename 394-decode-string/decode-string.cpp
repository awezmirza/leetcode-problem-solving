class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                string numStr = "";
                while (i < n && s[i] != '[') {
                    numStr += s[i];
                    i++;
                }
                st.push(numStr);
                i++;
            }

            if (s[i] >= 'a' && s[i] <= 'z') {
                string temp = "";
                while (i < n && s[i] >= 'a' && s[i] <= 'z') {
                    temp += s[i];
                    i++;
                }
                st.push(temp);
            }

            if (s[i] == ']') {
                string topStr = "";

                while (!st.empty() && (st.top()[0] < '0' || st.top()[0] > '9')) {
                    topStr = st.top() + topStr;
                    st.pop();
                }

                string mulStr = st.top();
                st.pop();
                int mul = stoi(mulStr);
                string t = "";
                for (int j = 0; j < mul; j++) {
                    t += topStr;
                }
                st.push(t);
                i++;
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};