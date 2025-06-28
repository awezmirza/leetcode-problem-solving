class Solution {

    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (pq.size() < k) {
                pq.push({nums[i], i});
            } else {
                if (pq.top().first < nums[i]) {
                    pq.pop();
                    pq.push({nums[i], i});
                }
            }
        }

        vector<pair<int, int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        sort(ans.begin(), ans.end(), comp);

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(ans[i].first);
        }

        return res;
    }
};