class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int low = newInterval[0];
        if(i<n){
            low = min(intervals[i][0], newInterval[0]);
        }
        int high = newInterval[1];
        while(i<n && intervals[i][1] <= high){
            i++;
        }
        if(i<n && high >= intervals[i][0]){
            ans.push_back({low, intervals[i][1]});
            i++;
        }
        else{
            if(i>0 && i<n){
                ans.push_back({low, max(intervals[i-1][1],high)});
            }
            else
                ans.push_back({low, high});
        }
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};