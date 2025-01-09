class Solution {

    bool isPref(string word, string pref) {
        int n1 = word.size();
        int n2 = pref.size();

        if (n1 < n2) {
            return false;
        }

        for (int i = 0; i < n2; i++) {
            if (word[i] != pref[i]) {
                return false;
            }
        }

        return true;
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string word : words) {
            if (isPref(word, pref)) {
                count++;
            }
        }
        return count;
    }
};