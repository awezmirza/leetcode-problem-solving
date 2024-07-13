class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> rbs;
        for (int i = 0; i < n; i++) {
            rbs.push_back({positions[i], i});
        }
        sort(rbs.begin(), rbs.end());

        stack<pair<int, int>> stRight;
        stack<pair<int, int>> stLeft;
        for (int i = 0; i < n; i++) {
            int psn = rbs[i].first;
            int idx = rbs[i].second;
            char dirn = directions[idx];            

            if (dirn == 'R') {
                stRight.push({psn, idx});
            } else {
                bool broke = false;
                while (!stRight.empty()) {
                    int tpIdx = stRight.top().second;
                    int tpHeal = healths[tpIdx];
                    int heal = healths[idx];
                    if (tpHeal == heal) {
                        stRight.pop();
                        broke = true;
                        break;
                    } else if (tpHeal > heal) {
                        healths[tpIdx]--;
                        broke = true;
                        break;
                    } else {
                        stRight.pop();
                        healths[idx]--;
                    }
                }
                if (!broke) {
                    stLeft.push({psn, idx});
                }
            }
        }

        vector<int> tempAns;
        while (!stLeft.empty()) {
            int idx = stLeft.top().second;
            tempAns.push_back(idx);
            stLeft.pop();
        }
        while (!stRight.empty()) {
            int idx = stRight.top().second;
            tempAns.push_back(idx);
            stRight.pop();
        }

        sort(tempAns.begin(), tempAns.end());

        vector<int> ans;
        for (auto tempAn : tempAns) {
            ans.push_back(healths[tempAn]);
        }

        return ans;
    }
};