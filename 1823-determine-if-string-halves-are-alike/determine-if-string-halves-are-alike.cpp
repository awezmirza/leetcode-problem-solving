class Solution {
public:
    bool isVowel(char& c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }

    bool halvesAreAlike(string s) {
        int end = s.size() - 1;
        int start = 0;
        int left = 0,right= 0;
        while(start<end){
            if(isVowel(s[start])) left++;
            if(isVowel(s[end])) right++;
            start++;
            end--;
        }
        if(left == right) return true;
        return false;
    }
};