class Node {
    public :
        char ch;
        unordered_map<char, Node*> next;
        int index;

        Node(char ch) {
            this->ch = ch;
            this->index = -1;
        }
    };

    class Trie {
        public :
        Node* root;
        Trie() { 
            root = new Node('#'); 
        }

        void insert(string s, int index) {
            reverse(s.begin(), s.end());
            Node* curr = root;
            for (auto c : s) {
                if (curr->next.find(c) == curr->next.end()) {
                    Node* ch = new Node(c);
                    curr->next[c] = ch;
                } 
                curr = curr->next[c];
            }
            curr->index = index;
        }

        void helper(Node* curr, vector<int>& ret, string s = "") {

            if (curr->index != -1) {
                int j = 0;
                int k = s.size() - 1;
                bool flag = true;
                while (j <= k) {
                    if (s[j] != s[k]) {
                        flag = false;
                        break;
                    }
                    j++, k--;
                }

                if (flag) {
                    ret.push_back(curr->index);
                }
            }

            for (auto m : curr->next) {
                char mpChar = m.first;
                s.push_back(mpChar);
                helper(curr->next[mpChar], ret, s);
                s.pop_back();
            }
        }

        vector<int> traverse(Node* curr, string word) {
            vector<int> ret;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];

                if (curr->index != -1) {
                    int j = i;
                    int k = word.size() - 1;
                    bool flag = true;
                    while (j < k) {
                        if (word[j] != word[k]) {
                            flag = false;
                            break;
                        }
                        j++, k--;
                    }

                    if (flag) {
                        ret.push_back(curr->index);
                    }
                }

                if (curr->next.find(c) == curr->next.end()) {
                    return ret;
                }
                    curr = curr->next[c];
            }

            helper(curr, ret);

            return ret;
        }
    };

class Solution {
public:

    vector<vector<int>> palindromePairs(vector<string>& words) {

        Trie t;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            string word = words[i];
            t.insert(word, i);
        }

        vector<vector<int>> ans;

        Node* root = t.root;

        for (int i = 0; i < n; i++) {
            vector<int> traverseTrie = t.traverse(root, words[i]);

            for (auto vec : traverseTrie) {
                if (i != vec) {
                    ans.push_back({i, vec});
                }
            }
        }

        return ans;
    }
};