class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for (auto ch : tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;
        for (int el : freq) {
            if (el > 0)
                pq.push(el);
        }

        int ans = 0;
        while (!pq.empty()) {

            vector<int> temp;
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    int fr = pq.top();
                    pq.pop();
                    fr--;
                    temp.push_back(fr);
                }
            }
            for (auto el : temp) {
                if (el > 0) {
                    pq.push(el);
                }
            }
            if (pq.empty()) {
                ans += temp.size();
            } else {
                ans += n + 1;
            }
        }
        return ans;
    }
};
