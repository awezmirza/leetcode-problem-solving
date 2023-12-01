class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ptr1=0;
        int ptr2=0;
        int s1 = 0;
        int s2 = 0;
        while(s1 < word1.size() && s2 < word2.size() ){
            if(word1[s1][ptr1++] != word2[s2][ptr2++]) return false;
            if(ptr1>=word1[s1].size()){
                s1++;
                ptr1 = 0;
            }
            if(ptr2>=word2[s2].size()){
                s2++;
                ptr2 = 0;
            }
        }
        return s1==word1.size() && s2 == word2.size();
    }
};