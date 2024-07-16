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

    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {

        if (!root || root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode* left = findLCA(root->left, startValue, destValue); 
        TreeNode* right = findLCA(root->right, startValue, destValue);

        if (left != NULL && right != NULL) {
            return root;
        } else if (left == NULL) {
            return right;
        } else {
            return left;
        }

    }

    bool findPath(string& path, int target, TreeNode* root) {
        if(root->val == target) {
            return true;
        }

        if (root->left) {
            path.push_back('L');
            if (findPath(path, target, root->left)) {
                return true;
            }
            path.pop_back();
        }

        if (root->right) {
            path.push_back('R');
            if (findPath(path, target, root->right)) {
                return true;
            }
            path.pop_back();
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);
        
        string pathLCAToSrc;
        string pathLCAToDest;
        
        findPath(pathLCAToSrc, startValue, LCA);
        findPath(pathLCAToDest, destValue, LCA);

        string ans;

        for (auto s : pathLCAToSrc) {
            ans.push_back('U');
        }

        for (auto s : pathLCAToDest) {
            ans.push_back(s);
        }
    
        return ans;
    }
};