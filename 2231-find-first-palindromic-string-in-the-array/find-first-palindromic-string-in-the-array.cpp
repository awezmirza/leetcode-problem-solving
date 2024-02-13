class Solution {
public:
    bool isPal(string& s){
        int st = 0;
        int end = s.size() - 1;
        while(st<end){
            if(s[st++]!= s[end--]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string word: words){
            if(isPal(word)) return word;
        }
        return "";
    }
};