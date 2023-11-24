class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxElem = piles[0];
        for(int elem : piles) maxElem = max(elem,maxElem);

        vector <int> freq(maxElem + 1);

        for(int elem : piles) freq[elem]++;

        int end = maxElem;

        int n = piles.size();
        int totalIts = n/3;
        int ans = 0;

        bool turn = 0;

        while(totalIts){
            if(freq[end]==0){
            end--;
            continue;
            }
            if(turn){
                ans += end;
                totalIts--;
            } 
            freq[end]--;
            turn = !turn;
        }
        return ans;
    }
};