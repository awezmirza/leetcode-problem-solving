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

    int operationsForCurrLevel(vector<int> arr) {
        vector<int> dupArr = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int n = dupArr.size();
        for (int i = 0; i < n; i++) {
            mp[dupArr[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dupArr[i] != arr[i]) {
                int idxOfVal = mp[arr[i]];
                mp[dupArr[i]] = idxOfVal;
                dupArr[idxOfVal] = dupArr[i];
                ans++;
            }
        }
        return ans;
    }

public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> currLevelVals;
            while (sz--) {
                TreeNode* fr = q.front();
                currLevelVals.push_back(fr->val);
                if (fr->left) {
                    q.push(fr->left);
                }
                if (fr->right) {
                    q.push(fr->right);
                }
                q.pop();
            }
            ans += operationsForCurrLevel(currLevelVals);
        }
        return ans;
    }
};