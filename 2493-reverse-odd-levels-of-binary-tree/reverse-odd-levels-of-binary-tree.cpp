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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        vector<int> currQ;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(level&1){
                    node->val = currQ[size-1-i];
                }

                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            currQ = temp;
            level++;
        }
        return root;
    }
};