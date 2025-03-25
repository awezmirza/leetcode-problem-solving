class Solution {

    bool isPossible(vector<vector<int>>& range, int& n) {
        sort(range.begin(), range.end());
        vector<vector<int>> newRange;

        int st = range[0][0];
        int en = range[0][1];
        int sz = range.size();

        for (int i = 1; i < sz; i++) {
            if (en <= range[i][0]) {
                newRange.push_back({st, en});
                st = range[i][0];
                en = range[i][1];
            } else {
                en = max(en, range[i][1]);
            }
        }
        newRange.push_back({st, en});

        return newRange.size() >= 3;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;

        for (auto rect : rectangles) {
            x.push_back({rect[0], rect[2]});
            y.push_back({rect[1], rect[3]});
        }

        return isPossible(x, n) || isPossible(y, n);
    }
};