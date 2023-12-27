class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size(), ans = 0, maxi, accSum, i = 0;
        while(i<n){
            maxi = accSum = neededTime[i];
            int lastIdx = i;
            i++;
            while(i<n){
                if(colors[i] == colors[lastIdx]) {
                    maxi = max(neededTime[i], maxi);
                    accSum += neededTime[i];
                    i++;
                }
                else{
                    ans += accSum - maxi;
                    break;
                }
            }
        }

        ans += accSum - maxi;

        return ans;
    }
};