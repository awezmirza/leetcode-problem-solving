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
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;

        for (auto description : descriptions) {
            st.insert(description[1]);

            TreeNode* parent = mp.find(description[0]) != mp.end() ? mp[description[0]] : new TreeNode(description[0]);
            TreeNode* child = mp.find(description[1]) != mp.end() ? mp[description[1]] : new TreeNode(description[1]);

            if (description[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            
            mp[description[0]] = parent;
            mp[description[1]] = child;
        }

        for (auto description : descriptions) {
            if (st.find(description[0]) == st.end()) {
                return mp[description[0]];
            }
        }

        return NULL;
    }
};