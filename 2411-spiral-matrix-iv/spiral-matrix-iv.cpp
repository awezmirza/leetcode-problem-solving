/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> ans(m, vector<int> (n, -1));
        vector<vector<int>> dirn = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int currCol = 0, currRow = 0;
        int currDirn = 0;
        int traversedRow = 0;
        int traversedCol = 0;

        while (head) {
            ans[currRow][currCol] = head->val;
            head = head->next;

            cout<<"("<<currRow<<","<<currCol<<")"<<" ";
            
            int newCol = currCol + dirn[currDirn][1];
            int newRow = currRow + dirn[currDirn][0];
            
            if (newCol >= n - traversedCol || newRow >= m - traversedRow || newCol < traversedCol || newRow < traversedRow) {
                currDirn = (currDirn + 1) % 4;
                if (currDirn == 0) {
                    traversedCol++;
                } else if (currDirn == 3) {
                    traversedRow++;
                }
                currCol += dirn[currDirn][1];
                currRow += dirn[currDirn][0];
            } else {
                currCol = newCol;
                currRow = newRow;
            }
        }
        return ans;
    }
};