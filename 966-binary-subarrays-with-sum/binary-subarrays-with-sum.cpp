class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int> freq;
        freq[0] = 1;
        int pfSum = 0;
        int ans = 0;
        for(int num:nums){
            pfSum += num;
            if(freq.count(pfSum - goal)){
                ans += freq[pfSum - goal];
            }
            freq[pfSum]++;
        }
        return ans;
    }
};