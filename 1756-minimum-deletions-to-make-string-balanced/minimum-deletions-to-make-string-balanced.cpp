class Solution {
public:

    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> prefixSum;
        int aCnt = 0;
        int bCnt = 0;
        for (int i = 0; i < n; i++) {
            prefixSum.push_back(aCnt);
            if (s[i] == 'a') {
                aCnt++;
            } else {
                bCnt++;
            }
        }

        // if (aCnt == 0 || bCnt == 0) {
        //     return 0;
        // }

        int ans = 100000009;

        for (int i = 0; i < n; i++) {
            int prevAs = prefixSum[i];
            int prevBs = i - prevAs;

            int forwardAs = aCnt - prevAs;
            if (s[i] == 'a') {
                forwardAs--;
            }

            ans = min(ans, prevBs + forwardAs);
        }

        return ans;
    }
};