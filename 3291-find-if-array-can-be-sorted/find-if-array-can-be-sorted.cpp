class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ppcnt;
        for (int num : nums) {
            ppcnt.push_back(__builtin_popcount(num));
        }
        int prevMaxi = -1;
        int currMaxi = INT_MIN;
        int currMin = INT_MAX;

        for (int i = 0; i < n;) {
            int currppCnt = ppcnt[i];

            while (i < n && currppCnt == ppcnt[i]) {
                currMaxi = max(currMaxi, nums[i]);
                currMin = min(currMin, nums[i]);
                i++;
            }
            if (currMin < prevMaxi) {
                return false;
            }
            prevMaxi = currMaxi;
            currMaxi = INT_MIN;
            currMin = INT_MAX;
        }


        // cout<<ppcnt[0]<<" ";
        // for (int i = 1; i < n; i++) {
        //     cout<<ppcnt[i]<<" ";
        //     if (currMin < prevMaxi) {
        //         return false;
        //     }
        //     if (ppcnt[i] == ppcnt[i - 1]) {
        //         currMaxi = max(currMaxi, nums[i]);
        //         currMin = min(currMin, nums[i]);
        //     } else {
        //         prevMaxi = currMaxi;
        //         currMaxi = nums[i];
        //         currMin = nums[i];
        //     }
        // }

        // vector<int> maxiInGrp(n, 0);
        // for (int i = 0; i < n; i) {
        //     int prevppcnt = ppcnt[i];
        //     while (i < n && ppcnt[i] == prevppcnt) {
                
        //     }
        // }
        return true;
    }
};