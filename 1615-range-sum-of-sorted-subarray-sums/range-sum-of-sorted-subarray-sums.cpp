class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int it = 1;
        int ans = 0;
        while (it <= right) {
            auto top = pq.top();
            int num = top.first;
            int idx = top.second;
            pq.pop();

            if (it >= left) {
                ans = (ans + (num % 1000000007)) % 1000000007;
            }
            if (idx < n - 1) {
                num += nums[idx + 1];
                pq.push({num, idx + 1});
            }
            it++;
        }
        return ans;
    }
};