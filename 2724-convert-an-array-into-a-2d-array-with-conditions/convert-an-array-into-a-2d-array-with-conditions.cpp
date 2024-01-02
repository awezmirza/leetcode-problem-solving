class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // vector<int> freq(201,0);
        unordered_map<int,int> freq;
        int maxi = 0;
        for(int el : nums){
            freq[el]++;
            maxi = max(maxi,freq[el]);
        }
        vector<vector<int>> ans(maxi);
        for(int i = 0;i<201;i++){
                int curr = 0;
                while(freq[i] > 0){
                    ans[curr].push_back(i);
                    curr++;
                    freq[i]--;
                }
        }    
        return ans;
    }
};