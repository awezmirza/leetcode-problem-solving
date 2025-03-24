class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int ans = meetings[0][0] - 1;
        
        int lastDay = meetings[0][1];
        
        for (int i = 1; i < n; i++) {
            if (meetings[i][0] - lastDay > 1) {
                ans += (meetings[i][0] - lastDay - 1);
            }

            lastDay = max(lastDay, meetings[i][1]);
        }

        return ans + days - lastDay;
    }
};