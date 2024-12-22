#define P pair<int, int>

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);
        unordered_map<int, vector<P>> mp;
        for (int i = 0; i < n; i++) {
            auto query = queries[i];
            sort(query.begin(), query.end());
            if (heights[query[0]] < heights[query[1]] || query[0] == query[1]) {
                ans[i] = query[1];
            } else {
                mp[query[1]].push_back({heights[query[0]], i});
            }
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        int k = heights.size();
        for (int i = 0; i < k; i++) {
            if (mp.count(i)) {
                for (auto p : mp[i]) {
                    pq.push(p);
                }
            }
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
        }
        return ans;
    }
};