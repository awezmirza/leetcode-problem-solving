class Solution {
public:
    bool cmp(vector<int>& s1Letters, vector<int>& s2Letters) {
        for (int i = 0; i < 26; i++) {
            if (s1Letters[i] != s2Letters[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return 0;
        }
        vector<int> s1Letters(26, 0);
        for (auto ch : s1) {
            s1Letters[ch - 'a']++;
        }
        vector<int> s2Letters(26, 0);
        int i = 0;
        int j = 0;
        while (j < n1) {
            s2Letters[s2[j] - 'a']++;
            j++;
        }

        while (j < n2) {
            if (cmp(s1Letters, s2Letters)) {
                return true;
            }
            s2Letters[s2[i] - 'a']--;
            s2Letters[s2[j] - 'a']++;
            i++, j++;
        }
        if (cmp(s1Letters, s2Letters)) {
            return true;
        }
        return false;
    }
};