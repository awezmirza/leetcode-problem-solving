class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ngtve;
        vector<int> pstve;
        vector<int> ans;
        int n = nums.size();
        for(int num:nums){
            if(num<0) ngtve.push_back(num);
            else pstve.push_back(num);
        }
        for(int i = 0;i<n;i++){
            if(i % 2 != 0) ans.push_back(ngtve[i/2]);
            else ans.push_back(pstve[i/2]);   
        }
        return ans;
    }
};