class Solution {
public:

    int distance (vector<int>& p1, vector<int>& p2) {
        return ((p1[0] - p2[0]) *  (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1]));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> mp;
        mp[distance(p1, p2)]++;
        mp[distance(p3, p2)]++;
        mp[distance(p4, p2)]++;
        mp[distance(p1, p3)]++;
        mp[distance(p1, p4)]++;
        mp[distance(p3, p4)]++;

        if (mp.size() != 2) {
            return false;
        }

        for (auto el : mp) {
            // return el.second == 4 || el.second == 2;
            if (el.first == 0) {
                return false;
            }
        }

        return 1;
    }
};