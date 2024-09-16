class Solution {
public:

    int findMinDiff(string t1, string t2) {
        int t1h = stoi(t1.substr(0, 2));
        int t1m = stoi(t1.substr(3, 2));

        int t2h = stoi(t2.substr(0, 2));
        int t2m = stoi(t2.substr(3, 2));

        int t1Min = t1h * 60 + t1m;
        int t2Min = t2h * 60 + t2m;

        int mini = min(t1Min - t2Min, t2Min - t1Min);
        int maxi = max(t1Min - t2Min, t2Min - t1Min);

        return min(mini + 1440, maxi);
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = 720;
        int n = timePoints.size();

        for (int i = 1; i < n; i++) {
            ans = min(ans, findMinDiff(timePoints[i], timePoints[i - 1]));
        }
        ans = min(ans, findMinDiff(timePoints[0], timePoints[n - 1]));
        return ans;
    }
};