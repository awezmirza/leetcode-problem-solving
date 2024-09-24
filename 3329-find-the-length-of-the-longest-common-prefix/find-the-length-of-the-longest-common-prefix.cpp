class Solution {

    struct Trie {
        vector<Trie*> next;
        Trie() : next(10) {}
    };

    void insert(Trie* root, string num) {
        Trie* iterator = root;
        for (char c : num) {
            if (!iterator->next[c - '0']) {
                
                iterator->next[c - '0'] = new Trie();
            }
            iterator = iterator->next[c - '0'];
        }
    }

    int find(Trie* root, string num) {
        Trie* iterator = root;
        int count = 0;
        int i = 0;
        int n = num.size();
        while (i < n) {
            char c = num[i];
            if (!iterator->next[c - '0']) {
                return count;
            }
            iterator = iterator->next[c - '0'];
            count++;
            i++;
        }
        return count;
    }
    

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = new Trie();
        for (int num : arr1) {
            insert(root, to_string(num));
        }
        
        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, find(root, to_string(num)));
        }
        return ans;
    }
};