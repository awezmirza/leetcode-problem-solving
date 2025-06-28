class Solution {

    auto static comp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> cp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cp.push_back({nums[i], i});
        }

        sort(cp.begin(), cp.end());

        vector<pair<int, int>> cp2;

        for (int i = n - k; i < n; i++) {
            cp2.push_back(cp[i]);
        }

        sort(cp2.begin(), cp2.end(), comp);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(cp2[i].first);
        }

        return ans;
    }
};