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
    void solve(TreeNode* root, int& ans, int& sumTillNow){
        if (!root->left && !root->right){
            ans += sumTillNow;
            return;
        }
        if(root->left){
            sumTillNow = sumTillNow*10 + root->left->val;
            solve(root->left, ans, sumTillNow);
            sumTillNow = sumTillNow/10;
        }
        if(root->right){
            sumTillNow = sumTillNow*10 + root->right->val;
            solve(root->right, ans, sumTillNow);
            sumTillNow = sumTillNow/10;
        }
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int sumTillNow = root->val;
        solve(root, ans, sumTillNow);
        return ans;
    }
};