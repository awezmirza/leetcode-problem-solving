class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101);
        for(int num: nums){
            freq[num]++;
        }
        sort(freq.rbegin(),freq.rend());
        int maxi = freq[0];
        int ptr = 0;
        int ans = 0;
        while(freq[ptr++] == maxi){
            ans += maxi;
        }
        return ans;
    }
};