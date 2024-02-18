#define ll long long
#define pii pair<ll,ll>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> allMeetingHosted(n,0);
        set<int> st;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }

        sort(meetings.begin(), meetings.end());
        for (auto meeting : meetings) {
            ll strt = meeting[0];
            ll end = meeting[1];
            while (!pq.empty() && pq.top().first <= strt) {
                st.insert(pq.top().second);
                pq.pop();
            }

            if (!st.empty()) {
                auto currRoomAdd = st.begin();
                allMeetingHosted[*currRoomAdd]++;
                pq.push({end, *currRoomAdd});
                st.erase(*currRoomAdd);
            }

            else {
                ll diffTime = end - strt;
                pii p = pq.top();
                pq.pop();
                st.insert(p.second);
                auto currRoomAdd = st.begin();
                allMeetingHosted[*currRoomAdd]++;
                pq.push({p.first + diffTime, *currRoomAdd});
                st.erase(*currRoomAdd);
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