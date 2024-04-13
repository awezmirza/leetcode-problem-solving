class Solution {
public:
    int countMaxAreaHistogram(vector<int>& histogram){
        int n = histogram.size();
        vector<int> prevLessIndex(n);
        vector<int> nextLessIndex(n);

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            while(st.top() != -1 && histogram[st.top()] >= histogram[i]) {
                    st.pop();
            }
            prevLessIndex[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        st.push(n);

        for (int i = n - 1; i >= 0; i--) {
            while(st.top() != n && histogram[st.top()] >= histogram[i]) {
                    st.pop();
            }
            nextLessIndex[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            int curr = (nextLessIndex[i] - prevLessIndex[i] - 1) * histogram[i];
            ans = max(ans, curr);
        }

        // cout<<"For histogram: "<<endl;
        // for(auto el: histogram){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
        // cout<<"prevLessIndex: "<<endl;
        // for(auto el: prevLessIndex){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
        // cout<<"nextLessIndex: "<<endl;
        // for(auto el: nextLessIndex){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> histogram(n, 0);

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                }
                else {
                    histogram[j] = histogram[j] + 1;
                }
            }
            ans = max(ans, countMaxAreaHistogram(histogram));
            // cout<<"After i = "<<i<<" ans is: "<<ans<<endl;
        }
        return ans;
    }
};