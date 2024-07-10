class Solution {
public:
    int minOperations(vector<string>& logs) {
        int currDepth = 0;

        for (auto log : logs) {
            if (log == "../") {
                currDepth = max(0, currDepth - 1);
            } else if (log != "./") {
                currDepth++;
            }
        }

        return currDepth;
    }
};