class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1);
        n--;
        while (n) {
            long tp = *st.begin();
            st.erase(tp);
            st.insert(tp * 2);
            st.insert(tp * 3);
            st.insert(tp * 5);
            n--;
        }
        return *st.begin();
    }
};