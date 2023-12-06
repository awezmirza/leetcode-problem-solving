class Solution {
public:
    int totalMoney(int n) {
        // int ans = 0;
        //     int div = n/7;
        //     ans = ans + div*28;
        //     int temp = div;
        //     div--;
        //     while(div>0){
        //         ans += div*7;
        //         div--;
        //     }
        //     int rem = n%7;
        //     while(rem){
        //         ans += temp + 1;
        //         temp++,rem--;
        //     }
        // return ans;


        int ans = 0;
        int div = n/7;
        // AP div/2(2*28 + (div-1)*7)
        ans = (div*(2*28 + (div-1)*7))/2;
        int rem = n%7;
        while(rem){
            ans += div + 1;
            div++,rem--;
        }
        return ans;
    }
};