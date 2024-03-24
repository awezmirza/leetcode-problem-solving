class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> freq(100001, 0);
        for(auto num:nums){
            if(freq[num]) return num;
            freq[num] = true;
        }
        return 0;
    }
};