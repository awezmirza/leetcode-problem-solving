class Solution {

    int binSrch(vector<int>& nums, bool findPositive) {
        int st = 0;
        int end = nums.size() - 1;

        int n = nums.size();
        int ans = n;

        while (st <= end) {
            int mid = (st + end) / 2;
            if (findPositive) {
                if (nums[mid] <= 0) {
                    st = mid + 1;
                } else if (nums[mid] > 0) {
                    end = mid - 1;
                    ans = min(ans, mid);
                }
            } else {
                if (ans == n) {
                    ans = -1;
                }
                if (nums[mid] >= 0) {
                    end = mid - 1;
                } else if (nums[mid] < 0) {
                    st = mid + 1;
                    ans = max(ans, mid);
                }
            }
        }

        return ans;
    }

public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = binSrch(nums, true);
        int neg = binSrch(nums, false);
        
        return max(n - pos, neg + 1);
    }
};