class Solution {
public:
    void findSubsets(int i, vector<int>& nums, int& cnt, int currOr, int& maxiOr) {
        if (i >= nums.size()) {
            if (currOr == maxiOr) {
                cnt++;
            }
            return;
        }
        findSubsets(i + 1, nums, cnt, currOr, maxiOr);
        findSubsets(i + 1, nums, cnt, currOr | nums[i], maxiOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxiOr = 0;
        for (int num : nums) {
            maxiOr = maxiOr | num;
        }
        int cnt = 0;
        findSubsets(0, nums, cnt, 0, maxiOr);
        
        return cnt;
    }
};