class Trie {
public:
    bool isEnd = false;
    vector<Trie*> next;
    Trie() : next(26, NULL) {}
};

class WordDictionary {
public:
    Trie* root = new Trie();
    WordDictionary() {}

    void addWord(string word) {
        Trie* iterator = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!iterator->next[word[i] - 'a']) {
                iterator->next[word[i] - 'a'] = new Trie();
            }
            iterator = iterator->next[word[i] - 'a'];
        }
        iterator->isEnd = true;
    }

    bool searchHelper(string word, Trie* iterator) {
        if (!iterator) {
            return false;
        }

        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] != '.') {
                if (iterator->next[word[i] - 'a'] == NULL) {
                    return false;
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    if (searchHelper(word.substr(i + 1), iterator->next[j])) {
                        return true;
                    }
                }
                return false;
            }
            iterator = iterator->next[word[i] - 'a'];
        }
        if (iterator->isEnd != true) {
            return false;
        }
        return true;
    }

    bool search(string word) {
        return searchHelper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */