class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastOccG = 0, lastOccP = 0, lastOccM = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int j = 0;
            while(j<garbage[i].size()){
                if(garbage[i][j] == 'G'){
                    ans += 1 + lastOccG;
                    lastOccG = 0;
                }
                else if(garbage[i][j] == 'P'){
                    ans += 1 + lastOccP;
                    lastOccP = 0;
                }
                else{
                    ans += 1 + lastOccM;
                    lastOccM = 0;
                }
                j++;
            }
            if(i != n-1){
                lastOccP += travel[i];
                lastOccG += travel[i];
                lastOccM += travel[i];
            }
        }
        return ans;
    }
};