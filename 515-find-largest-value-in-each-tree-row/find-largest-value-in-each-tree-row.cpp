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
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int maxi = INT_MIN;
            while (sz--) {
                TreeNode* fr = q.front();
                q.pop();
                maxi = max(maxi, fr->val);
                if (fr->left) {
                    q.push(fr->left);
                }
                if (fr->right) {
                    q.push(fr->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};