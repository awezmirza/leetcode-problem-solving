class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftHighest = 0;
        int rightLowest = n;

        for (auto num : left) {
            leftHighest = max(leftHighest, num);
        }

        for (auto num : right) {
            rightLowest = min(rightLowest, num);
        }

        return max(leftHighest, n - rightLowest);
    }
};