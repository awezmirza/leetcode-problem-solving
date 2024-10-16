class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        string ans = "";
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});

        while (pq.top().first > 0) {
            auto maxi = pq.top();
            pq.pop();
            int n = ans.size();
            if (n > 1 && (ans[n - 1] == ans[n - 2] && ans[n - 1] == maxi.second)) {
                auto tmp = maxi;
                maxi = pq.top();
                pq.pop();
                pq.push(tmp);
                if (maxi.first == 0) {
                    break;
                }
            } 
            ans.push_back(maxi.second);
            pq.push({maxi.first - 1, maxi.second});
        }

        return ans;
    }
};