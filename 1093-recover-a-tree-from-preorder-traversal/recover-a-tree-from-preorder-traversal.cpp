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
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = new TreeNode();

        stack<TreeNode*> st;
        st.push(root);

        int currLvl = -1;
        int dashes = 0;
        int i = 0;

        while (i < traversal.size()) {
            if (traversal[i] == '-') {
                dashes = 0;
                while (traversal[i] == '-') {
                    dashes++;
                    i++;
                }
            } else {

                int val = 0;
                while (i < traversal.size() && traversal[i] != '-') {
                    val = val * 10 + (traversal[i] - '0');
                    i++;
                }

                while (currLvl != dashes - 1) {
                    currLvl--;
                    st.pop();
                }

                TreeNode* tp = st.top();
                if (!tp->left) {
                    tp->left = new TreeNode(val);
                    st.push(tp->left);
                } else {
                    tp->right = new TreeNode(val);
                    st.push(tp->right);
                }
                currLvl++;
            }
        }


        return root->left;
    }
};