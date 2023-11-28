class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        int sze = corridor.size();
        long ans = 1;
        int crrPlnts = 0;
        int s = 0;
        for(int i = 0;i<sze;i++){
            if(s==2){
                while(corridor[i] == 'P' && i<sze){
                    crrPlnts++;
                    i++;
                }
                if(corridor[i]=='S'){
                    ans = (ans*(crrPlnts + 1))%mod;
                    crrPlnts = 0;
                    s = 0;
                }
            }
            if(corridor[i] == 'S') s++;
        }
        if(s==0 || s==1) return 0;
        return ans;
    }
};