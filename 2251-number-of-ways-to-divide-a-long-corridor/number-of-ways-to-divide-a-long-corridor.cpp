class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        int sze = corridor.size();
        long ans = 0;
        int crrPlnts = 0;
        int s = 0;
        for(int i = 0;i<sze;i++){
            if(s==2){
                while(corridor[i] == 'P' && i<sze){
                    crrPlnts++;
                    i++;
                }
                if(corridor[i]=='S'){
                    if(ans == 0) ans = crrPlnts + 1;
                    else ans = (ans*(crrPlnts + 1))%mod;
                    crrPlnts = 0;
                    s = 0;
                }
            }
            if(corridor[i] == 'S') s++;
        }
        if(s==1) return 0;
        if(s==2 && ans == 0) return 1;
        else return ans;
    }
};