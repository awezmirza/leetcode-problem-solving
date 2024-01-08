class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {

        set<int> st(nums.begin(),nums.end());
        int n = moveTo.size();
        for(int i = 0;i<n;i++){
            st.erase(moveFrom[i]);
            st.insert(moveTo[i]);
        }
        vector<int> ans;
        for(auto pr : st){
            ans.push_back(pr);
        }
        return ans;
    }
};