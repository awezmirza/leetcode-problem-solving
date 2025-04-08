class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxiNum = 0;
        int time = 0;
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > time) {
                maxiNum = num;
                time = mp[num];
            }
        }

        int cntOfMaxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxiNum) {
                cntOfMaxi++;
            }

            if ((((i + 1) / 2) + 1) <= cntOfMaxi && ((n - i - 1) / 2) + 1 <= time - cntOfMaxi) {
                return i;
            }
        }

        return -1;
    }
};