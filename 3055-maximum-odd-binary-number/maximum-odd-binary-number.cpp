class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(auto ch:s){
            if(ch=='1') ones++;
        }
        int zeroes = s.size() - ones;
        string ans;
        while(ones>1){
            ans.push_back('1');
            ones--;
        }
        while(zeroes--){
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;
    }
};