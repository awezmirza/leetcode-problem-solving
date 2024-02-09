class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        int taskPtr = tasks.size() - 1;
        int ans = 0;

        while(taskPtr >= 0){
            int maxAns = -1;
            for(int i = 0;i<processorTime.size();i++){
                int maxOfLastFour = -1;
                for(int j = 0;j<4;j++){
                    maxOfLastFour = max(maxOfLastFour,tasks[taskPtr--]);
                }
                maxAns = max(processorTime[i] + maxOfLastFour,maxAns);
            }
            ans += maxAns;
        }
        return ans;
    }
};