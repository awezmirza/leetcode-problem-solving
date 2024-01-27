class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(),usageLimits.end());

        long long ans = 0;
        long long currSum = 0;
        for(int i = 0;i<n;i++){
            currSum+=usageLimits[i];

            long long haveElems = (ans+1)*(ans+2)/2;

            if(currSum >= haveElems){
                ans++;
            }
            // else{
            //     currSum-=usageLimits[i];
            // }
        }
        return ans;
    }
};