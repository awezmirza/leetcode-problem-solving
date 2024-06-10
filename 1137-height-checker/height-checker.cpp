class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101);
        for (int height : heights) {
            freq[height]++;
        }

        int n = heights.size();
        int ans = 0;
        int freqPtr = 0;

        for (int i = 0; i < n; i++) {

            while (freq[freqPtr] == 0 && freqPtr <= 100) {
                freqPtr++;
            }

            if(heights[i] != freqPtr) {
                ans++;
            }

            freq[freqPtr]--;
        }

        return ans;
    }
};