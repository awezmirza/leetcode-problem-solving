class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long ans = 0;
        int currMaxi = maximumHeight[0];
        for (int num : maximumHeight) {
            currMaxi = min(num, currMaxi);
            ans += currMaxi--;
            cout<<currMaxi;
        }
        if (currMaxi < 0) {
            return -1;
        } 
        return ans;
    }
};