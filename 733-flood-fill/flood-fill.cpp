class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col, int color, int tgt) {
        int m = image.size();
        int n = image[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || image[row][col] != tgt || image[row][col] == color) {
            return;
        }

        image[row][col] = color;

        // Up
        dfs(image, row - 1, col, color, tgt);

        // Down
        dfs(image, row + 1, col, color, tgt);

        // Left
        dfs(image, row, col - 1, color, tgt);

        // Right
        dfs(image, row, col + 1, color, tgt);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int tgt = image[sr][sc];
        dfs(image, sr, sc, color, tgt);
        return image;
    }
};