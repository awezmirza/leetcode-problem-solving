class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size();
        int ans = 0, maxi, accSum ;

        for(int i =0;i<n;i){
            maxi = neededTime[i];
            accSum = neededTime[i];
            int lastIdx = i;
            i++;
            while(i<n){
                if(cout<<colors[lastIdx]<<","<<colors[i]<<endl,colors[i] == colors[lastIdx]) {
                    maxi = max(neededTime[i], maxi);
                    accSum += neededTime[i];
                    i++;
                }
                else{
                    ans += accSum - maxi;
                    maxi = 0;
                    accSum = 0;
                    // i++;
                    break;
                }
            }
        }

        ans += accSum - maxi;

        return ans;
    }
};