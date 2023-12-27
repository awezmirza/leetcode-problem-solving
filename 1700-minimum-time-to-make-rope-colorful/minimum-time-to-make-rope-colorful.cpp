class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size();
        int ans = 0, maxi, accSum ;

        int i = 0;
        while(i<n){
            maxi = neededTime[i];
            accSum = neededTime[i];
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
                    maxi = 0;
                    accSum = 0;
                    break;
                }
            }

        }

        ans += accSum - maxi;

        return ans;
    }
};