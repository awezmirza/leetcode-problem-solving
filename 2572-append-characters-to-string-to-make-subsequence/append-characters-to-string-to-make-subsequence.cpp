class Solution {
public:
    int appendCharacters(string s, string t) {
        int sPtr = 0;
        int tPtr = 0;

        int sSize = s.size();
        int tSize = t.size();

        while(sPtr < sSize && tPtr < tSize){
            if(s[sPtr] == t[tPtr]){
                tPtr++;
            }
            sPtr++;
        }

        return tSize - tPtr;
    }
};