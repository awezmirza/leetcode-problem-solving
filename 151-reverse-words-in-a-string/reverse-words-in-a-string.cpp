class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {
            string temp = "";
            while (i >= 0 && s[i] != ' ') {
                temp.push_back(s[i]);
                i--;
            }
            if (temp != "") {
                reverse(temp.begin(), temp.end());
                ans += (temp + " ");
            }
            i--;
        }
        ans.pop_back();
        return ans;
    }
};