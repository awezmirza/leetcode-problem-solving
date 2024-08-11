class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);
        long long i = 1;
        while (i < n) {
            long long tp = *(st.begin());
            st.erase(tp);
            st.insert(tp * 2);
            st.insert(tp * 3);
            st.insert(tp * 5);
            i++;
        }
        return *(st.begin());
    }
};