class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int, string>> pr;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            string name = names[i];
            pr.push_back({height, name});
        }
        
        sort(pr.begin(), pr.end(), greater());

        vector<string> ans;
        for (auto [height, name] : pr) {
            ans.push_back(name);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};