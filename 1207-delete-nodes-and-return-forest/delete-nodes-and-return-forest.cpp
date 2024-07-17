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

    // void dfs(set<TreeNode*>& ans, unordered_set<int>& to_delete, TreeNode* root) {
    //     if (!root) {
    //         return;
    //     }

    //     dfs(ans, st, root->left);
    //     dfs(ans, st, root->right);
    // }

    void deleteTree(vector<TreeNode*>& ans, unordered_set<int>& st, TreeNode* root, bool parent, TreeNode* parentNode, bool isLeft) {

        if (!root) {
            return;
        }
        
        if (st.find(root->val) != st.end()) {
            deleteTree(ans, st, root->left, false, root, true);
            deleteTree(ans, st, root->right, false, root, false);
            if (parentNode) {
                if (isLeft) {
                    parentNode->left = NULL;
                } else
                    parentNode->right = NULL;
            }
            // delete(root);
        } else { 
            if (!parent) {
                ans.push_back(root);
            }
            deleteTree(ans, st, root->left, true, root, true);
            deleteTree(ans, st, root->right, true, root, false);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for (auto dlt : to_delete) {
            st.insert(dlt);
        }

        deleteTree(ans, st, root, false, NULL, false);

        return ans;
    }
};