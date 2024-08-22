class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        int i = 0;
        while (i < n) {
            if (path[i] == '/') {
                while (i < n - 1 && path[i + 1] == '/') {
                    i++;
                }

                if ((i == n - 3 && path[i + 1] == '.' && path[i + 2] == '.') || (i < n - 3 && path[i + 3] == '/' && path[i + 1] == '.' && path[i + 2] == '.')) {
                    if (!st.empty()) {
                        st.pop();
                    }
                    i += 3;
                } else if ((i < n - 2 && (path[i + 1] == '.') && path[i + 2] == '/') || (i == n - 2 && path[i + 1] == '.')) {
                    i += 2;
                    continue;
                } else if (i < n - 1) {
                    string temp = "/";
                    i++;
                    while (i < n && path[i] != '/') {
                        temp.push_back(path[i]);
                        i++;
                    }
                    st.push(temp);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        stack<string> st2;

        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        string ans = "";
        while (!st2.empty()) {
            ans += st2.top();
            st2.pop();
        }

        return ans == "" ? "/" : ans;
    }
};