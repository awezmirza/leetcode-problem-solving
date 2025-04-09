class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini = 101;
        unordered_set<int> st;
        for (int num : nums) {
            mini = min(mini, num);
            st.insert(num);
        }
        if (k > mini) {
            return -1;
        }

        if (mini == k) {
            return st.size() - 1;
        }

        return st.size();
    }
};