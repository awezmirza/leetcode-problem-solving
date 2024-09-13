class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> cumXor;
        cumXor.push_back(arr[0]);
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            cumXor.push_back(arr[i] ^ cumXor[i - 1]);
        }
        vector<int> ans;
        for (auto query : queries) {
            if (query[0] == 0) {
                ans.push_back(cumXor[query[1]]);
            } else {
                ans.push_back(cumXor[query[0] - 1] ^ cumXor[query[1]]);
            }
        }
        return ans;
    }
};