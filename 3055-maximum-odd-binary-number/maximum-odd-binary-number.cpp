class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.size() == 1) return "1";
        int right = s.size() - 1;
        int left = 0;
        while(left<=right){
            if(s[left] == '1') left++;
            if(s[right] == '0') right--;
            if(left<right && s[left] =='0' && s[right] =='1') swap(s[left++],s[right--]);
        }
        swap(s[left-1],s[s.size()-1]);
        return s;
    }
};