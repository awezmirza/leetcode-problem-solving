class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(2);
        st.insert(3);
        while (st.find(n) == st.end()) {
            if (n == 1) {
                return true;
            }
            st.insert(n);
            int temp = 0;
            while (n) {
                int dig = n % 10;
                n /= 10;
                temp += (dig * dig);
            }
            n = temp;
        }
        return false;
    }
};