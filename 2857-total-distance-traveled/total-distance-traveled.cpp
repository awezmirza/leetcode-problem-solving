class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank > 0) {
            if (mainTank >= 5) {
                ans += 50;
                mainTank -= 5;
                if(additionalTank){
                    mainTank++;
                    additionalTank--;
                }
            }
            else{
                ans += (mainTank * 10);
                break;
            } 
        }
        return ans;
    }
};