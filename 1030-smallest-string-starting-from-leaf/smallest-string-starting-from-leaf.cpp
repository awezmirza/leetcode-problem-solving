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

    void updateAnsIfSmaller(string& currStr, string& ans){
        string temp = currStr;
        reverse(temp.begin(), temp.end());
        if(ans == ""){
            ans = temp;
            return;
        }
        int n = min(temp.size(), ans.size());
        for(int i = 0; i < n; i++){
            if(temp[i] < ans[i]){
                ans = temp;
                return;
            }
            else if(temp[i] > ans[i]){
                return;
            }
        }
        if(ans.size() > n){
            ans = temp;
        }
    }

    void dfs(TreeNode* root, string& currStr, string& ans){
        currStr.push_back(root->val + 'a');
        if(!root->left && !root->right){
            updateAnsIfSmaller(currStr, ans);
        }
        if(root->left){
            dfs(root->left, currStr, ans);
        }
        if(root->right){
            dfs(root->right, currStr, ans);
        }
        currStr.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string currStr = "";
        dfs(root, currStr, ans);
        return ans;
    }
};