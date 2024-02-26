class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(n,1);
        for(int x = m - 2;x>=0;x--){
            vector<int> curr(n,1);
            for(int y = n-2;y>=0;y--){
                curr[y] = temp[y] + curr[y + 1];
            }
            temp = curr;
        }
        return temp[0];
    }
};