#define ll long long
#define pii pair<ll,ll>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> allMeetingHosted(n,0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        sort(meetings.begin(), meetings.end());
        for (auto meeting : meetings) {
            ll strt = meeting[0];
            ll end = meeting[1];
            while (!pq.empty() && pq.top().first <= strt) {
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            if (!freeRooms.empty()) {
                int currRoom = freeRooms.top();
                freeRooms.pop();
                allMeetingHosted[currRoom]++;
                pq.push({end, currRoom});
            }

            else {
                ll diffTime = end - strt;
                pii p = pq.top();
                pq.pop();
                freeRooms.push(p.second);
                freeRooms.pop();
                int currRoom = freeRooms.top();
                allMeetingHosted[currRoom]++;
                pq.push({p.first + diffTime, currRoom});
            }
        }
        
        int maxi = 0, ans = 0;
        for(int i = 0;i<n;i++){
            if(maxi < allMeetingHosted[i]){
                maxi = allMeetingHosted[i];
                ans = i;
            }
        }
        return ans;
    }
};