class Solution {
public:

    bool ans(string& expression, int idx, int ops) {

        int n = expression.size();
        stack<char> st;
        stack<char> stOps;
        int currOp = 0;

        for (int i = 0; i < n; i++) {
            if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!') {
                stOps.push(expression[i]);
            } else if (expression[i] == 't' || expression[i] == 'f' || expression[i] == '(') {
                st.push(expression[i]);
            } else if (expression[i] == ')') {
                int topOp;
                if (stOps.top() == '&') {
                    topOp = 1;
                } else if (stOps.top() == '|') {
                    topOp = 2;
                } else {
                    topOp = 3;
                }
                stOps.pop();

                bool currAns = st.top() == 'f' ? false : true;
                st.pop();
                if (st.top() == '(' && topOp == 3) {
                    currAns = !currAns;
                }

                while (st.top() != '(') {
                    bool topex = st.top() == 'f' ? false : true;
                    if (topOp == 1) {
                        currAns = currAns & topex;
                    } else {
                        currAns = currAns | topex;
                    }
                    st.pop();
                }
                st.pop();
                if (currAns) {
                    st.push('t');
                } else {
                    st.push('f');
                }
            }
        }
        return st.top() == 'f' ? false : true;
    }

    bool parseBoolExpr(string expression) {
        // And = 1
        // Or = 2
        // Not = 3
        return ans(expression, 0, 0);
    }
};