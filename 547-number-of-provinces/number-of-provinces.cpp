class Solution {
public:

    void dfs(int num, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[num] = true;

        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[num][i] == 1) {
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, visited, isConnected);
            }
        }

        return ans;
    }
};