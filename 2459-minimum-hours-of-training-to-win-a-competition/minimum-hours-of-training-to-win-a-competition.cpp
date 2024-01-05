class Solution {
public:
    int minNumberOfHours(int initEnergy, int initExp, vector<int>& energy, vector<int>& exp) {
        int n = energy.size();
        int hrs = 0;

        for(int i = 0;i<n;i++){

            if(initExp <= exp[i]){
                hrs += exp[i] - initExp + 1;
                initExp += exp[i] - initExp + 1;
            }
            initExp += exp[i];

            if(initEnergy <= energy[i]){
                hrs += energy[i] - initEnergy + 1;
                initEnergy += energy[i] - initEnergy + 1;
            }
            initEnergy -= energy[i];
        }

        return hrs;


    }
};