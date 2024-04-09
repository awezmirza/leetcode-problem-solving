class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> q;
        int ans = 0;
        for (int ticket : tickets) {
            q.push(ticket);
        }
        while (true) {
            int fr = q.front();
            q.pop();
            fr--;
            ans++;
            if(fr == 0){
                if(k == 0){
                    return ans;
                }
                n--;
            }
            else{
                q.push(fr);
            }
            k = k - 1 < 0 ? n - 1 : k - 1;
        }
        return ans;
    }
};