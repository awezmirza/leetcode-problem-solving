class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s1[i] != ' ') {
                word.push_back(s1[i]);
                i++;
            }
            mp[word]++;
        }
        int m = s2.size();
        for (int i = 0; i < m; i++) {
            string word = "";
            while (i < m && s2[i] != ' ') {
                word.push_back(s2[i]);
                i++;
            }
            mp[word]++;
        }
        vector<string> ans;
        for (auto [key, val] : mp) {
            if (val == 1) {
                ans.push_back(key);
            }
        }
        return ans;
    }
};