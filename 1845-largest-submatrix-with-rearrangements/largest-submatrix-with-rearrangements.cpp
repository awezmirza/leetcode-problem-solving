class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       int ans = 0;

       vector<pair<int,int>> prvHts;

       for(int i = 0;i<n;i++){
           int prvSze = prvHts.size();
            vector<bool> visited(m,0);
           
           vector<pair<int,int>> currHts;

           for(auto [j,h]:prvHts){
               if(matrix[i][j] == 1){
                   currHts.push_back({j,h+1});
               }
               visited[j] = 1;
            }
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1 && visited[j]==false){
                    currHts.push_back({j,1});
                }
            }
            int currSze = currHts.size();
            for(int j = 0;j<currSze;j++){
                ans = max(ans,(j+1)*(currHts[j].second));
            }
            prvHts = currHts;
       }

        return ans;
    }
};

