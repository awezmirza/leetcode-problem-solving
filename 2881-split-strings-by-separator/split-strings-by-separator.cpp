class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words,
                                         char separator) {
        int n = words.size();
        vector<string> ans;
        for (auto word : words) {
            string curr = "";
            for (auto ch : word) {
                if (ch == separator) {
                    if (curr != "") {
                        ans.push_back(curr);
                    }
                    curr = "";
                } else {
                    curr += ch;
                }
            }
            if (curr != "") {
                ans.push_back(curr);
            }
            curr = "";
        }
        return ans;
    }
};