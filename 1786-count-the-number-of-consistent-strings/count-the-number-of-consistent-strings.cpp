class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedHash(26, 0);
        for (auto allowedChar : allowed) {
            allowedHash[allowedChar - 'a'] = true;
        }
        int count = 0;
        for (string word : words) {
            bool flag = false;
            for (char letter : word) {
                if (allowedHash[letter - 'a'] == false) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                count++;
            }
        }
        return count;
    }
};