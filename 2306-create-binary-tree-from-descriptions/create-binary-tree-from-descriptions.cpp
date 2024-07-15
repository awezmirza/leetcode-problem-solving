/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        unordered_set<int> st;
        for (auto description : descriptions) {
            st.insert(description[1]);
            if (mp.find(description[0]) != mp.end()) {
                if (mp.find(description[1]) != mp.end()) {
                    if (description[2] == 1) {
                        mp[description[0]]->left = mp[description[1]];
                    } else {
                        mp[description[0]]->right = mp[description[1]];
                    }
                } else {
                    TreeNode* nd = new TreeNode(description[1]);
                    mp[description[1]] = nd;
                    if (description[2] == 1) {
                        mp[description[0]]->left = nd;
                    } else {
                        mp[description[0]]->right = nd;
                    }
                }
            } else {
                TreeNode* pr = new TreeNode(description[0]);
                if (mp.find(description[1]) != mp.end()) {
                    if (description[2] == 1) {
                        pr->left = mp[description[1]];
                    } else {
                        pr->right = mp[description[1]];
                    }
                } else {
                    TreeNode* nd = new TreeNode(description[1]);
                    mp[description[1]] = nd;
                    if (description[2] == 1) {
                        pr->left = nd;
                    } else {
                        pr->right = nd;
                    }
                }
                mp[description[0]] = pr;
            }
            // mp[description[0]]->left 
        }

        for (auto description : descriptions) {
            description[0];
            if (st.find(description[0]) == st.end()) {
                return mp[description[0]];
            }
        }


        TreeNode* root = new TreeNode(5);
        return root;
    }
};