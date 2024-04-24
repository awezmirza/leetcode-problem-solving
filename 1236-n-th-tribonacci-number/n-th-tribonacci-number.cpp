class Solution {
public:
    int tribonacci(int n) {
        int n0 = 0, n1 = 1, n2 = 1;

        if(n == 0) return n0;
        if(n == 1) return n1;
        
        for(int i = 0; i < n - 2; i++){
            int temp = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};