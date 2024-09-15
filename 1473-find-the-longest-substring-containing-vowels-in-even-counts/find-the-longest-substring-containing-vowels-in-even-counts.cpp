class Solution {
public:
    int findTheLongestSubstring(string s) {
        int bitm = 0;
        unordered_map<char, int> mp = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        int n = s.size();
        unordered_map<int, int> intIdx = {{0, -1}};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                bitm = bitm ^ mp[s[i]];
            }
            
            if (intIdx.count(bitm)) {
                ans = max(ans, i - intIdx[bitm]);
            } else {
                intIdx[bitm] = i;
            }
        }
        return ans;
    }
};