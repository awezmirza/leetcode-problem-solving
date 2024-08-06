class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (auto c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (i < 8) {
                ans += freq[i];
            } else if (i < 16) {
                ans += (2 * freq[i]);
            } else if (i < 24) {
                ans += (3 * freq[i]);
            } else {
                ans += (4 * freq[i]);
            }
        }

        return ans;
    }
};