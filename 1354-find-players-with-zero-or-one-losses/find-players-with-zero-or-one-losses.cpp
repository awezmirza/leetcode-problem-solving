class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> noLoss, oneLoss, moreLoss;
        for (auto match : matches) {
            if (moreLoss.find(match[0]) == moreLoss.end() &&
                oneLoss.find(match[0]) == oneLoss.end() &&
                noLoss.find(match[0]) == noLoss.end()) {
                noLoss.insert(match[0]);
            }

            if (moreLoss.find(match[1]) == moreLoss.end() &&
                oneLoss.find(match[1]) == oneLoss.end()) {
                oneLoss.insert(match[1]);
                noLoss.erase(match[1]);
            } else {
                moreLoss.insert(match[1]);
                oneLoss.erase(match[1]);
            }
        }

        vector<int> noLossAns, oneLossAns;

        for (auto el : noLoss) {
            noLossAns.push_back(el);
        }
        for (auto el : oneLoss) {
            oneLossAns.push_back(el);
        }

        // sort(noLossAns.begin(), noLossAns.end());
        // sort(oneLossAns.begin(), oneLossAns.end());

        return {noLossAns, oneLossAns};
    }
};