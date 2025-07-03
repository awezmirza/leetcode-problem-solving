class Solution {

    string gen(string& prev) {
        string newStr = "";

        for (char &ch : prev) {
            char newCh = ch + 1;
            if (newCh > 'z') {
                newCh = 'a';
            }
            newStr.push_back(newCh);
        }

        return newStr;
    }

public:
    char kthCharacter(int k) {
        string ans = "a";

        while (ans.size() < k) {
            string newStr = gen(ans);

            ans += newStr;
        }

        return ans[k - 1];
    }
};