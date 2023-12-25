class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int s = 0;
        int e = (rows*cols) -1;
        int mid = e >> 1;   

        while(s <= e){
            if(target == matrix[mid/cols][mid%cols]){
                return true;
            }
            else if(target > matrix[mid/cols][mid%cols]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s +((e-s)>>1);
        }
        return false;
    }
};