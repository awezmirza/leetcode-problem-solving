class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        priority_queue<pair<int, string>, vector<pair<int, string>>> pq;

        int n = names.size();
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            string name = names[i];
            pq.push({height, name});
        }

        vector<string> ans;
        while (!pq.empty()) {
            string name = pq.top().second;
            ans.push_back(name);
            pq.pop();
        }
        return ans;
    }
};