class Solution {

public:

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> rows(n);
        vector<int> cols(m);
        // unordered_set <int> rowsTrack;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                    }
            }
        }

        for(int i = 0;i<n;i++){
            //  if(rowsTrack.find(i) != rowsTrack.end()){
            //     continue;
            // }

            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && rows[i] ==1 && cols[j]==1){
                    ans++;
                    // rowsTrack.insert(i);
                    break;
                }
            }
        }

        return ans;
    }
};