class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < 20; i++){
            int xoredVal = 0;
            for(auto el : nums){
                int masked = (1 << i) & el;
                xoredVal = xoredVal^masked; 
            }

            int kBitVal = (1 << i) & k;
            if(kBitVal != xoredVal) ans++;
        }
        return ans;
    }
};