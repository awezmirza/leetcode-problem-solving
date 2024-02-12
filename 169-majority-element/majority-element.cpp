class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int tgt = n/2;
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
            if(freq[num] > tgt ) return num;
        }
        return 0;
    }
};