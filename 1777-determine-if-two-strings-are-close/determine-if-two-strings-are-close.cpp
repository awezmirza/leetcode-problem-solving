class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int n = word1.size();
        vector<int> freqWord1(26,0), freqWord2(26,0);
        vector<bool> isPresent1(26,0), isPresent2(26,0);
        for(int i = 0;i<n;i++){
            freqWord1[word1[i] - 'a']++, freqWord2[word2[i] - 'a']++;
            isPresent1[word1[i] - 'a'] = true, isPresent2[word2[i] - 'a'] = true;
        }
        sort(freqWord1.begin(),freqWord1.end());
        sort(freqWord2.begin(),freqWord2.end());

        if(freqWord1 != freqWord2 || isPresent1 != isPresent2) return false;
        return true;
    }
};