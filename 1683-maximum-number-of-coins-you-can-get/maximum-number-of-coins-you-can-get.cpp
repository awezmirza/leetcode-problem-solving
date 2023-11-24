class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int totalIts = n/3;
        int it = n-2;
        int ans = 0;
        while(totalIts){
            ans += piles[it];
            it -= 2;
            totalIts--;
        }
        return ans;
    }
};