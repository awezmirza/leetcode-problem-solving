class Solution {
public:
    int rev(int n){
        int ans = 0;
        while(n){
            ans = ans*10+ n%10;
            n=n/10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int mod = 1000000007;
        int ans = 0;
        unordered_map <int,int> freqs;
        for(int elem : nums){
            int value = elem - rev(elem);
            ans = (ans + freqs[value])%mod;
            freqs[value]++;
        }
        return ans;
    }
};