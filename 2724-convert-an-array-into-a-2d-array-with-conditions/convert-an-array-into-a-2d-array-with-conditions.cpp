class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(201,0);
        int maxi = 0;
        for(int el : nums){
            freq[el]++;
            maxi = max(maxi,freq[el]);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<maxi;i++){
            vector<int> inside;
            for(int i = 0;i<201;i++){
                if(freq[i] > 0){
                    inside.push_back(i);
                    freq[i]--;
                }
            }
            ans.push_back(inside);
        }    
        return ans;
    }
};