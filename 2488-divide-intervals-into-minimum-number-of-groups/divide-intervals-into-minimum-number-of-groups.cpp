class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<int> st;
        sort(intervals.begin(), intervals.end());
        for (auto interval : intervals) {
            int strt = interval[0];
            int end = interval[1];

            int firstEl = *(st.begin());
            if (st.size() > 0 && strt > firstEl) {
                st.erase(st.begin());
            } 
            st.insert(end);
        }
        return st.size();
    }
};