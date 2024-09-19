class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
                string sign;
                sign.push_back(s[i]);
                st.push(sign);
                i++;
            } else if (s[i] != ' ') {
                string currNum = "";
                while (i < n && s[i] != '+' && s[i] != '-' && s[i] != '/' && s[i] != '*'  && s[i] != ' ') {
                    currNum.push_back(s[i]);
                    i++;
                }
                if (st.empty()) {
                    st.push(currNum);
                } else {
                    string sign = st.top();
                    st.pop();
                    if (sign == "+") {
                        st.push(currNum);
                    } else if (sign == "-") {
                        st.push(sign + currNum);
                    } else {
                        string tpNum = st.top();
                        st.pop();
                        int tpInt = stoi(tpNum);
                        int currInt = stoi(currNum);
                        if (sign == "*") {
                            st.push(to_string(tpInt * currInt));
                        } else {
                            st.push(to_string(tpInt / currInt));
                        }
                    }
                }
            } else {
                i++;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};