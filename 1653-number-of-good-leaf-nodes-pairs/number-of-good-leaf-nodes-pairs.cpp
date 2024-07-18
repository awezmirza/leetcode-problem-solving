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

    void makeGraph(TreeNode* root, TreeNode* parentNode, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafNodes ) {

        if (!root) {
            return;
        }

        if (parentNode) {
            adj[root].push_back(parentNode);
            adj[parentNode].push_back(root);
        }

        if (!root->left && !root->right) {
            leafNodes.insert(root);
        }

        makeGraph(root->left, root, adj, leafNodes);
        makeGraph(root->right, root, adj, leafNodes);
    }

    int countPairs(TreeNode* root, int distance) {

        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leafNodes;
        makeGraph(root, NULL, adj, leafNodes);

        int ans = 0;

        for (TreeNode* leaf : leafNodes) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for (int lvl = 0; lvl <= distance; lvl++) {
                int size = q.size();
                while (size--) {
                    TreeNode* front = q.front();
                    q.pop();
                    if (front != leaf && leafNodes.find(front) != leafNodes.end()) {
                        ans++;
                    }
                    for (auto nbr : adj[front]) {
                        if (visited.find(nbr) == visited.end()) {
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
            
        }
        return ans / 2;
    }
};