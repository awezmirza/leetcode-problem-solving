class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int empolyeesEligible = 0;
        for(int hour:hours){
            if(hour>=target) empolyeesEligible++;
        }
        return empolyeesEligible;
    }
};