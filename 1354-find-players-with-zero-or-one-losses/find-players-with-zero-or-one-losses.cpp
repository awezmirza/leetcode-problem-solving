class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> noLoss; // 1,2,5
        unordered_set<int> oneLoss; // 6 
        unordered_set<int> moreLoss; // 3
        for (auto match : matches) {
            if (moreLoss.find(match[0]) == moreLoss.end()) {
                if (oneLoss.find(match[0]) == oneLoss.end()) {
                    if (noLoss.find(match[0]) == noLoss.end()) {
                        noLoss.insert(match[0]);
                    }
                }
            }

            if (moreLoss.find(match[1]) == moreLoss.end()) {
                if (oneLoss.find(match[1]) == oneLoss.end()) {
                    oneLoss.insert(match[1]);
                        noLoss.erase(match[1]);
                } else {
                    moreLoss.insert(match[1]);
                    oneLoss.erase(match[1]);
                }
            }
        }

        vector<int> noLossAns;
        vector<int> oneLossAns;

        for (auto el : noLoss) {
            noLossAns.push_back(el);
        }
        for (auto el : oneLoss) {
            oneLossAns.push_back(el);
        }

        sort(noLossAns.begin(), noLossAns.end());
        sort(oneLossAns.begin(), oneLossAns.end());

        return {noLossAns, oneLossAns};
    }
};