class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> st;

        for (auto& path : folder) {
            string curr = "/";

            int i = 1;
            bool flag = false;
            while (i < path.size()) {

                if (flag) {
                    break;
                }
                
                while (i < path.size() && path[i] != '/') {
                    if (flag) {
                        break;
                    }
                    curr.push_back(path[i]);
                    i++;
                }

                if (st.contains(curr)) {
                    flag = true;
                }

                curr.push_back('/');

                i++;
            }

            if (!flag) {
                st.insert(path);
            }
        }

        vector<string> ans;

        for (auto &str : st) {
            ans.push_back(str);
        }

        return ans;
    }
};