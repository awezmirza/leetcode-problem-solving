class Solution {
public:

    pair<int, int> getCoordinated(int num, int n) {
        num--;
        int row = n - ((num / n) + 1);

        int postRow = n - row;
        int col = num % n;
        if (postRow % 2 == 0) {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        q.push(1);
        unordered_set<int> visited;
        visited.insert(1);
        int n = board.size();
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                int fr = q.front();
                q.pop();
                if (fr == n * n) {
                    return ans;
                }

                for (int k = 1; k < 7; k++) {
                    if (visited.find(fr + k) == visited.end()) {                        
                        if (fr + k > n * n) {
                            break;
                        }
                        pair<int, int> xy = getCoordinated(fr + k, n);
                        int x = xy.first;
                        int y = xy.second;

                        if (board[x][y] != -1) {
                            q.push(board[x][y]);
                        } else {
                            q.push(fr + k);
                        }
                        visited.insert(fr + k);
                    }
                }
                size--;
            }
            ans++;
        }
        return -1;
        
    }
};