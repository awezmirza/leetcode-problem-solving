class Solution {

    struct Trie {
        Trie* next[26] = {};
        int currCnt = 0;
    };

    void insert(Trie* root, string& s) {
        Trie* iterator = root;
        for (char& c : s) {
            if (!iterator->next[c - 'a']) {
                iterator->next[c - 'a'] = new Trie();
            }
            iterator = iterator->next[c - 'a'];
            iterator->currCnt++;
        }
    }

    int prefixScore(Trie* root, string& s) {
        Trie* iterator = root;
        int count = 0;
        for (char& c : s) {
            if (!iterator->next[c - 'a']) {
                return count;
            }
            iterator = iterator->next[c - 'a'];
            count += iterator->currCnt;
        }
        return count;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for (string& word : words) {
            insert(root, word);
        }
        int n = words.size();
        vector<int> ans;
        for (string& word : words) {
            ans.push_back(prefixScore(root, word));
        }
        return ans;
    }
};