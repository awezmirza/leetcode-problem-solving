class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int idx, int currDay, vector<vector<int>>& dp) {
        int n = days.size();
        
        if (idx >= n) {
            return 0;
        }

        if (currDay > 365) {
            return 1000004;
        }

        if (dp[idx][currDay] != -1) {
            return dp[idx][currDay];
        }

        if (currDay > days[idx]) {
            return solve(days, costs, idx + 1, currDay, dp);
        }

        // 1 Day wala lege
        int oneDay = 1000001;
        if (days[idx] == currDay) {
            oneDay = costs[0] + solve(days, costs, idx + 1, currDay + 1, dp);
        } else {
            oneDay = solve(days, costs, idx, currDay + 1, dp);
        }

        // 7 Day wala lege
        int sevenDay = costs[1] + solve(days, costs, idx + 1, currDay + 7, dp);

        // 30 Day wala lege
        int thirtyDay = costs[2] + solve(days, costs, idx + 1, currDay + 30, dp);

        return dp[idx][currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() + 1;
        vector<vector<int>> dp(n, vector<int> (366, -1));
        int ans = solve(days, costs, 0, days[0], dp);
        return ans;
    }
};