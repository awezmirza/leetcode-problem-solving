class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i){
            int last = i++;
            while(s[i] == s[last] && i<n){ 
                ++i;
            }
            if(i - last >= 3) ans.push_back({last, i-1});
        }
        return ans;
    }
};