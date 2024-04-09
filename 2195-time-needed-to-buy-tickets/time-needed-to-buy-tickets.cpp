class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        int tgt = tickets[k];
        for (int i = 0; i < n; i++) {
            if (tickets[i] < tgt) {
                ans += tickets[i];
            } else {
                ans += tgt;
            }
            if (i == k){
                tgt--;
            }
        }
        return ans;
    }
};