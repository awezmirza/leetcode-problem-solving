class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> freq(256, {0, 0});
        for (auto ch : s) {
            freq[ch].first++;
            freq[ch].second = ch;
        }
        sort(freq.begin(), freq.end(),greater());
        string ans = "";
        for (auto el : freq) {
            while (el.first > 0) {
                ans.push_back(el.second);
                el.first--;
            }
        }
        return ans;
    }
};