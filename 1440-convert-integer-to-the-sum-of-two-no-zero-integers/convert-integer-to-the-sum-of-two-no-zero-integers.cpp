class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        srand((unsigned)time(NULL));
        int a=0, b= 0, tens=1;
        for (; n>0; n/=10, tens*=10) {
            int d=n%10;
            if (d==0) {
                // borrow from next digit
                unsigned x=rand()%9+1;// rand [1, 9]
                a+=x*tens;
                b+=(10-x)*tens;
                n-=10;  // subtract from the next digit
            } 
            else if (d==1 && n>=10) {
                unsigned x=rand()%8+2;// rand [2, 9]
                a+=x*tens;
                b+=(11-x)*tens;
                n-=10;  // borrow
            } 
            else {
                // normal split
                unsigned x=(d==1)?1:rand()%(d-1)+1;// rand [1, d-1]
                a+=x*tens;
                b+=(d-x)*tens;
            }
        }
        return {a, b};
    }
};
