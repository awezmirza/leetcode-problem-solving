class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double currentWait = 0;
        int currTime = 0;

        for (auto custom : customers) {
            if (currTime <= custom[0]) {                
                currTime = custom[0] + custom[1];
            }
            else {
                currentWait += currTime - custom[0];
                currTime += custom[1];
            }
            currentWait += custom[1];
        }

        return currentWait/customers.size();
    }
};