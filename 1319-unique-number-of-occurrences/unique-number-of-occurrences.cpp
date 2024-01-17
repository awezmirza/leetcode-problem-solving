class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int el:arr){
            mp[el]++;
        }
        unordered_set<int> st;
        for(auto el:mp){
            if(st.find(el.second) == st.end()) st.insert(el.second);
            else return false;
        }
        return true;
    }
};