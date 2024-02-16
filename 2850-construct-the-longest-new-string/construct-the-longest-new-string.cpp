class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        if(x > y) ans += (2 * y + 1);
        else if(y > x) ans += (2 * x + 1);
        else ans += 2*y;
        ans += z;
        return ans*2;
    }
};