class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> q;
        int ans = 0;
        for (int ticket : tickets) {
            q.push(ticket);
        }
        while (!(q.front() == 1 && k == 0)) {
            int fr = --q.front();
            q.pop();
            ans++;
            if(fr == 0){
                n--;
            }
            else{
                q.push(fr);
            }
            k = k - 1 < 0 ? n - 1 : k - 1;
        }
        return ans + 1;
    }
};