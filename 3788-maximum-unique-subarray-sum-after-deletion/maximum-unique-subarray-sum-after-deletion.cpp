class Solution {
public:
    int maxSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        if (nums.back() < 0) {
            return nums.back();
        }

        unordered_set<int> st;

        int ans = 0;

        for (int num : nums) {
            if (num > 0 && !st.contains(num)) {
                ans += num;
                st.insert(num);
            }
        }

        return ans;
    }
};