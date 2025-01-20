class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            if (st.count(num)) {
                st.erase(num);
            } else {
                st.insert(num);
            }
        }

        vector<int> ans;

        for (auto val : st) {
            ans.push_back(val);
        }

        return ans;
    }
};