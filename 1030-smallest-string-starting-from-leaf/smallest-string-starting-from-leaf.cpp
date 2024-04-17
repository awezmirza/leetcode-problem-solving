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
        if(ans == ""){
            ans = currStr;
            return;
        }

        int currSize = currStr.size();
        int ansSize = ans.size();

        int currStrPtr = currStr.size() - 1;
        int ansPtr = ans.size() - 1;

        while(ansPtr >= 0 && currStrPtr >= 0){
            if(currStr[currStrPtr] < ans[ansPtr]){
                ans = currStr;
                return;
            }
            else if(currStr[currStrPtr] > ans[ansPtr]){
                return;
            }
            ansPtr--;
            currStrPtr--;
        }
        if(ansSize > currSize){
            ans = currStr;
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};