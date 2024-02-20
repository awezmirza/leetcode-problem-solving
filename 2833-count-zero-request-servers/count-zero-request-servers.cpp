class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int queSize = queries.size();
        vector<pair<int,int>> sortedQueries;
        for(int i = 0;i<queSize;i++) sortedQueries.push_back({queries[i],i});
        sort(sortedQueries.begin(), sortedQueries.end());

        sort(logs.begin(),logs.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});
        int lgSze = logs.size();

        vector<int> ans(queSize, 0);

        int uniqueServerAcc = 0;
        int left = 0, right = 0;
        unordered_map<int, int> srvrAcc;

        for(auto it : sortedQueries){
            int time = it.first;
            int idx = it.second;

            while(right < lgSze && logs[right][1] <= time){
                if(srvrAcc[logs[right][0]] == 0) uniqueServerAcc++;
                srvrAcc[logs[right][0]]++;
                right++;
            }

            while(left < lgSze && logs[left][1] < time - x){
                if(srvrAcc[logs[left][0]] == 1) uniqueServerAcc--;
                srvrAcc[logs[left][0]]--;
                left++;
            }

            ans[idx] = n - uniqueServerAcc;
        }

        
        return ans;
    }
};