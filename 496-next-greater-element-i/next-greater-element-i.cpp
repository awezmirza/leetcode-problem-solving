class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nextGreaterOfNum2(n, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && nums2[st.top()] <= num) {
                st.pop();
            }
            if (!st.empty()) {
                nextGreaterOfNum2[i] = nums2[st.top()];
            }
            st.push(i);
            mp[num] = i;
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreaterOfNum2[mp[num]]);
        }
        return ans;

    }
};