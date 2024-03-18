class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxi = points[0][1];
        int ans = 0;
        for(auto el:points){
            if(maxi<el[0]){
                ans++;
                maxi = el[1];
            }
            else if(maxi > el[1]){
                maxi = el[1];
            }
        }
        ans++;
        return ans;
    }
};