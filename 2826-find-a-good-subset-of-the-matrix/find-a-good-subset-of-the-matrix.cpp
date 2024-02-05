class Solution {
public:

    int convertToNum(vector<vector<int>>& grid, int row){
        int size = grid[0].size();
        int val = 0;
        for(int col= 0;col<size;col++){
            if(grid[row][col] == 1){
                val += (1 << col);
            }
        }
        return val;
    }

    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> gridRowVal(32,-1);
        for(int row= 0;row<rows;row++){
            int val = convertToNum(grid,row);
            if(val == 0){
                return {row};
            }
            gridRowVal[val] = row;
        }
        for(int i=0;i<32;i++){
            if(gridRowVal[i] == -1) continue;
            for(int j = i+1;j<32;j++){
                if(gridRowVal[j] == -1 || (j & i) != 0) continue;
                int row1 = gridRowVal[i];
                int row2 = gridRowVal[j];
                return {min(row1,row2),max(row2,row1)};
            }
        }
        return {};
    }
};