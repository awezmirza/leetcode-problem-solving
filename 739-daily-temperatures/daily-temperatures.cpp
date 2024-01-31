class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i = n-1;i>=0;i--){
            if(!st.empty() && temperatures[st.top()]>temperatures[i]){
                ans[i] = st.top() - i;
            }
            else if(!st.empty()){
                while(!st.empty()){
                    if(temperatures[st.top()]>temperatures[i]){
                        ans[i] = st.top() - i;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};