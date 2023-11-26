class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<pair<int,int>> previousHeights;

        for(int i=0;i<n;i++){
            vector<pair<int,int>> currHeights;
            vector<bool> visited(m);
            for(auto [j,h] : previousHeights){
                if(matrix[i][j]){
                    currHeights.push_back({j,h+1});
                }
                visited[j]=true;
            }


            for(int j=0;j<m;j++){
                if(!visited[j] && matrix[i][j]){
                    currHeights.push_back({j,1});
                }
            }
            for(int j=0;j<currHeights.size();j++){
                ans = max(ans,(j+1)*currHeights[j].second);
            }
            previousHeights = currHeights;
        }


        return ans;
    }
};

