class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }
        vector<pair<int, int>> newArr;
        for (int i = 0; i < n; i++) {
            newArr.push_back({arr[i], i});
        }
        sort(newArr.begin(), newArr.end());
        vector<pair<int, int>> ans;
        int rank = 1;
        ans.push_back({1, newArr[0].second});
        for (int i = 1; i < n; i++) {
            if (newArr[i].first != newArr[i - 1].first) {
                rank++;
            }
            ans.push_back({rank, newArr[i].second});
        }
        auto custom = [] (auto a, auto b) {
            return a.second < b.second;
        };
        sort(ans.begin(), ans.end(), custom);
        vector<int> res;
        for (auto pr : ans) {
            res.push_back(pr.first);
        }
        return res;
    }
};