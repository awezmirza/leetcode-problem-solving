class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int rightWall = n - 1;
        int leftWall = 0;
        int topWall = 0;
        int bottomWall = m - 1;

        while (leftWall <= rightWall && topWall <= bottomWall) {
            // Right
            for (int i = leftWall; i <= rightWall; i++) {
                ans.push_back(matrix[topWall][i]);
            }
            topWall++;

            // Down
            for (int i = topWall; i <= bottomWall; i++) {
                ans.push_back(matrix[i][rightWall]);
            }
            rightWall--;

            // Left
            if (topWall <= bottomWall){
                for (int i = rightWall; i >= leftWall; i--) {
                    ans.push_back(matrix[bottomWall][i]);
                }
                bottomWall--;
            }

            // Up
            if (leftWall <= rightWall){
                for (int i = bottomWall; i >= topWall; i--) {
                    ans.push_back(matrix[i][leftWall]);
                }
                leftWall++;
            }
        }
        return ans;
    }
};