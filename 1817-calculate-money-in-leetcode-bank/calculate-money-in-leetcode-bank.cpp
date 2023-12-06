class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
            int div = n/7;
            ans = ans + div*28;
            int temp = div;
            div--;
            while(div>0){
                ans += div*7;
                div--;
            }
            int rem = n%7;
            while(rem){
                ans += temp + 1;
                temp++,rem--;
            }
        return ans;
    }
};