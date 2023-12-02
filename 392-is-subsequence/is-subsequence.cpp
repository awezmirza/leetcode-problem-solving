class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPtr = 0,sSize = s.size();
        int tPtr = 0,tSize = t.size();

        while(sPtr < sSize){
            if(tPtr >= tSize) return false;
            if(s[sPtr] == t[tPtr]){
                sPtr++,tPtr++;
            }
            else{
                tPtr++;
            }
        }
        return true;
        
    }
};