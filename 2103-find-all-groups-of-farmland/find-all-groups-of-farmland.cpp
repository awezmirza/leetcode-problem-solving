class Solution {
public:

    vector<int> acquireLand(vector<vector<int>>& land, int i, int j){

        int m = land.size();
        int n = land[0].size();

        int lastCol = j;
        while(lastCol < n && land[i][lastCol] == 1){
            lastCol++;
        }
        int lastRow = i;
        while(lastRow < m && land[lastRow][j] == 1){
            lastRow++;
        }

        for(int ii = i; ii < lastRow; ii++){
            for(int jj = j; jj < lastCol; jj++){
                land[ii][jj] = 0;
            }
        }

        return {lastRow - 1, lastCol - 1};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(land[i][j] == 1){

                    vector<int> currGroup;
                    currGroup.push_back(i);
                    currGroup.push_back(j);

                    vector<int> grpEnd = acquireLand(land, i, j);
                    currGroup.push_back(grpEnd[0]);
                    currGroup.push_back(grpEnd[1]);
                    
                    ans.push_back(currGroup);
                }
            }
        }

        return ans;
    }
};