class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // int m = img.size(), n = img[0].size();
        // vector<vector<int>> ans(m, vector<int> (n));

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         int total = 0, cnt = 0;
        //         for(int row = i-1;row<=i+1;row++){
        //             for(int col = j-1;col<=j+1;col++){
        //                 if(col < 0 || row < 0 || row >= m || col >= n){
        //                     continue;
        //                 }
        //                 total += img[row][col];
        //                 cnt++;
        //             }
        //         }
        //         ans[i][j] = total/cnt;

        //     }
        // }
        // return ans;

        // In-place
        int m = img.size(), n = img[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int total = 0, cnt = 0;
                for(int row = i-1;row<=i+1;row++){
                    for(int col = j-1;col<=j+1;col++){
                        if(col < 0 || row < 0 || row >= m || col >= n){
                            continue;
                        }
                        total += (img[row][col] % 256);
                        cnt++;
                    }
                }
                img[i][j] |= (total/cnt << 8);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                img[i][j] >>= 8;
            }
        }

        return img;
    }
};