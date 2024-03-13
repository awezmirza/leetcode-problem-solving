class Solution {
public:
    int pivotInteger(int n) {
        vector<int> pfSum(n+1);
        for(int i = 1;i<=n;i++){
            pfSum[i] = i + pfSum[i-1];
        }
        int totSum = pfSum[n];
        for(int i = 1;i<=n;i++){
            if(pfSum[i] == totSum - pfSum[i-1]){
                return i;
            }
        }
        return -1;
    }
};