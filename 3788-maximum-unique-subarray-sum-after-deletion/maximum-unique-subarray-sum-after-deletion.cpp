class Solution {
public:
    int maxSum(vector<int>& nums) {

        unordered_set<int> st;

        int maxi = -100;
        int ans = 0;

        for (int num : nums) {
            if (num > 0 && !st.contains(num)) {
                ans += num;
                st.insert(num);
            }

            maxi = max(maxi, num);
        }

        if (maxi < 0) {
            return maxi;
        }

        return ans;
    }
};