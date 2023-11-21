class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastOccG =0, lastOccP =0, lastOccM =0, ans = 0;
        for(int i = 0;i<n;i++){
            for(char c : garbage[i]){
                if(c == 'G'){
                    ans += 1 + lastOccG;
                    lastOccG = 0;
                }
                else if(c == 'P'){
                    ans += 1 + lastOccP;
                    lastOccP = 0;
                }
                else{
                    ans += 1 + lastOccM;
                    lastOccM = 0;
                }
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