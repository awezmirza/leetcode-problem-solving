class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int end = 0;
        int scoreInWindow = 0;
        
        while (end < windowSize) {
            scoreInWindow += cardPoints[end];
            end++;
        }
        int ans = scoreInWindow;
        int start = 0;
        while (end < n) {
            scoreInWindow += cardPoints[end];
            scoreInWindow -= cardPoints[start];
            ans = min(ans, scoreInWindow);
            start++;
            end++;
        }

        int totalScore = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return totalScore - ans;
    }
};