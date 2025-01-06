class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<pair<int, int>> left(n);
        vector<pair<int, int>> right(n);
        for (int i = 1; i < n; i++) {
            left[i].second = boxes[i - 1] - '0' + left[i - 1].second;
            left[i].first = left[i - 1].first + left[i - 1].second + boxes[i - 1] - '0';

            right[n - i - 1].second = boxes[n - i] - '0' + right[n - i].second;
            right[n - i - 1].first = right[n - i].first + right[n - i].second + boxes[n - i] - '0';
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = left[i].first + right[i].first;
        }

        return ans;
    }
};