class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> ptsX;
        for(auto point : points){
            ptsX.push_back(point[0]);
        }
        sort(ptsX.begin(),ptsX.end());
        int n = ptsX.size();
        int maxi = 0;
        for(int i = 1;i<n;i++){
            if(ptsX[i] - ptsX[i-1] > maxi) maxi = ptsX[i] - ptsX[i-1];
        }
        return maxi;
    }
};