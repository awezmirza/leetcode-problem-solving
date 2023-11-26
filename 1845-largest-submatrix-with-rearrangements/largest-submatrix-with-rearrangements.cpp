class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int>prevVal= matrix[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    if(i!=0){
                        prevVal[j]++;
                    }
                }
                else prevVal[j]=0;
            }
            vector<int> currRow = prevVal;
            sort(currRow.begin(),currRow.end(),greater());
            for(int j=0;j<m;j++){
                ans = max(ans,currRow[j] * (j+1));
            } 
        }
        return ans;
    }
};

// class Solution {
// public:
//     int largestSubmatrix(vector<vector<int>>& matrix) {
//         vector<vector<int>> copy = matrix;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int ans = 0;
        
//         for(int row=0;row<m;row++){
//             for(int col=0;col<n;col++) if(matrix[row][col] !=0 && row > 0) matrix[row][col] += matrix[row -1][col];
//             vector<int> currRow = matrix[row];
//             sort(currRow.begin(),currRow.end(),greater());
//             for(int j=0;j<n;j++) ans = max(ans,currRow[j] * (j+1));
//         }
//         return ans;
//     }
// };