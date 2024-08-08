class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1 , 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int steps = 0;
        int dir = 0;
        ans.push_back({rStart, cStart});
        while (ans.size() < rows * cols) {
            if (dir == 0 || dir == 2) {
                steps++;
            }
            for (int cnt = 0; cnt < steps; cnt++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart < rows && rStart >= 0 && cStart < cols && cStart >= 0) {
                    ans.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};