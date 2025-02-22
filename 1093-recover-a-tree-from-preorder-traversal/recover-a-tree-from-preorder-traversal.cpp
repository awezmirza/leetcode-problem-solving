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

    int takeNum(string& traversal, int& i) {
        int val = 0;

        while (i < traversal.size() && traversal[i] != '-') {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        return val;
    }

    int countDashes(string& traversal, int& i) {
        int dashes = 0;
        while (traversal[i] == '-') {
            dashes++;
            i++;
        }
        return dashes;
    }

    void emptyStack(int& currLvl, int& dashes, stack<TreeNode*>& st) {
        while (currLvl != dashes - 1) {
            currLvl--;
            st.pop();
        }
    }

    void insertInTreeAndStack(stack<TreeNode*>& st, int& val) {
        TreeNode* tp = st.top();
        if (!tp->left) {
            tp->left = new TreeNode(val);
            st.push(tp->left);
        } else {
            tp->right = new TreeNode(val);
            st.push(tp->right);
        }
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = new TreeNode();

        stack<TreeNode*> st;
        st.push(root);

        int currLvl = -1, dashes = 0, i = 0;

        while (i < traversal.size()) {
            if (traversal[i] == '-') {
                dashes = countDashes(traversal, i);
            } else {
                int val = takeNum(traversal, i);
                emptyStack(currLvl, dashes, st);
                insertInTreeAndStack(st, val);                
                currLvl++;
            }
        }

        return root->left;
    }
};