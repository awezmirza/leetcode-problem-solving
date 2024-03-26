class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0] == 1 ? 2 : 1;
        bool nFnd = 0;
        for (int num : nums) {
            if (num == n)
                nFnd = 1;
            if (num < n && num >= 0) {
                int ptr = num;
                while (ptr < n && ptr >= 0 && nums[ptr] != INT_MIN) {
                    int tmp = nums[ptr];
                    nums[ptr] = INT_MIN;
                    ptr = tmp;
                    cout << ptr << endl;
                    if (ptr == n)
                        nFnd = 1;
                }
            }
        }
        for (auto el : nums)
            cout << el << " " << nFnd;
        for (int i = 1; i < n; i++) {
            if (nums[i] != INT_MIN)
                return i;
        }
        if (nFnd)
            return n + 1;
        return n;
    }
};