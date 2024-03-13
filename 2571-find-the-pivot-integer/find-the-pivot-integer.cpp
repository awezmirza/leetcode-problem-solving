class Solution {
public:
    int pivotInteger(int n) {
        vector<int> pfSum(n+1);
        for(int i = 1;i<=n;i++){
            pfSum[i] = i + pfSum[i-1];
        }
        int totSum = pfSum[n];
        int st = 1, end = n;
        while(st<=end){
            int mid = (st + end)/2;
            if(pfSum[mid] == totSum - pfSum[mid - 1]) return mid;
            else if(pfSum[mid] < totSum - pfSum[mid - 1]){
                st = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
        return -1;
    }
};