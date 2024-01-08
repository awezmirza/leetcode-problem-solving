class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,bool> mp;
        for(int num : nums){
            mp[num] = true;
        }
        int n = moveTo.size();
        for(int i = 0;i<n;i++){
            mp[moveFrom[i]] = false;
            mp[moveTo[i]] = true;
        }
        vector<int> ans;
        for(auto pr : mp){
            if(pr.second) ans.push_back(pr.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};