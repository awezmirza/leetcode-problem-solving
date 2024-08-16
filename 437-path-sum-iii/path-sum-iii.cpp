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

    void dfs(TreeNode* root, int targetSum, int& ans, unordered_map<long long, int>& mp, long long currSum) {
        if (!root) {
            return;
        }

        currSum += root->val;

        cout<<currSum<<" ";

        ans += (mp[currSum - targetSum]);

        mp[currSum]++;

        if (root->left) {
            dfs(root->left, targetSum, ans, mp, currSum);
        }
        if (root->right) {
            dfs(root->right, targetSum, ans, mp, currSum);
        }

        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        int ans = 0;
        mp[0] = 1;
        dfs(root, targetSum, ans, mp, 0);
        return ans;
    }
};