class Solution {
public:
    bool isAnswer(int i,int j, vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        for(int l = 0;l<m;l++){
                        if(mat[i][l] == 1 && l != j){
                            return false;
                        }
                    }
        for(int l = 0;l<n;l++){
            if(mat[l][j] == 1 && l != i){
                return false;
            }
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    if(isAnswer(i,j,mat)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};