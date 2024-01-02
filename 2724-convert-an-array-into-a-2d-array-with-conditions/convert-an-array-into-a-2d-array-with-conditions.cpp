class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(201,0);
        // unordered_map<int,int> freq;
        // int maxi = 0;
        vector<vector<int>> ans;
        int ansSize = 0;
        for(int el : nums){
            if(freq[el] >= ansSize ){
                ans.push_back({el});
                ansSize++;
            } 
            else ans[freq[el]].push_back(el);
            freq[el]++;
        }
        return ans;
    }
};