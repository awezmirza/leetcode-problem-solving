class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<long long,long long> mp;
        mp[0] = 1;

        int cumXor = 0;
        for(auto ch : word){

            int shift = ch - 'a';
            int num = 1 << shift;
            cumXor ^= num;

            ans += mp[cumXor];

            for(int i = 0; i < 10; i++){
                int thisNum = 1 << i;
                long long oddCumXor = (cumXor ^ thisNum);
                ans += mp[oddCumXor];
            }
            mp[cumXor]++;
        }
        return ans;
    }
};