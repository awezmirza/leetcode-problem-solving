class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 0;

        vector<vector<int>> intMatrix(rows, vector<int> (cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                intMatrix[i][j] = matrix[i][j] == '0' ? 0 : 1;
            }
        }

        for (int i = 0; i < rows; i++) {
            if (i != 0) {
                for (int j = 0; j < cols; j++) {                
                    intMatrix[i][j] = (1 + intMatrix[i - 1][j]) * intMatrix[i][j];
                }
            }

            vector<int> prevLesser(cols);
            stack<int> st;
            st.push(-1);
            for (int j = 0; j < cols; j++) {
                while (st.top() != -1 && intMatrix[i][st.top()] >= intMatrix[i][j]) {
                    st.pop();
                }
                prevLesser[j] = st.top();
                st.push(j);
            }

            vector<int> nextLesserIndexes(cols);
            stack<int> st2;
            st2.push(cols);
            for (int j = cols - 1; j >= 0; j--) {
                while (st2.top() != cols && intMatrix[i][st2.top()] >= intMatrix[i][j]) {
                    st2.pop();
                }
                nextLesserIndexes[j] = st2.top();
                st2.push(j);
            }

            for (int j = 0; j < cols; j++) {
                int nxtLesser = nextLesserIndexes[j];
                int prvLesser = prevLesser[j];
                int currHeight = intMatrix[i][j];

                int currArea =( (j - prvLesser) + (nxtLesser - j) - 1) * currHeight;
                ans = max(ans, currArea);

            }
        }

        return ans;
    }
};