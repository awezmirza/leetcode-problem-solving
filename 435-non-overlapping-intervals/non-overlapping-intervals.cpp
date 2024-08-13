class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (auto const& a, auto const& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        int ans = 0;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            int currBegin = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevBegin = intervals[prev][0];
            int prevEnd = intervals[prev][1];

            if (prevEnd > currBegin) {
                ans++;
            } else {
                prev = i;
            }
        }
        return ans;
    }
};