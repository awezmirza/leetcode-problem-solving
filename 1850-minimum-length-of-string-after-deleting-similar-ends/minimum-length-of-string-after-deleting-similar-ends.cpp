class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int sze = s.size();
        int end = sze -1;
        while(start<end){
            if(s[start] != s[end]) break;
            char stCh = s[start];
            char enCh = s[end];
            while(s[start] == stCh && start <= end){
                start++;
                sze--;
            }
            while(s[end] == enCh && start <= end){
                end--;
                sze--;
            }
        }
        return sze;
    }
};