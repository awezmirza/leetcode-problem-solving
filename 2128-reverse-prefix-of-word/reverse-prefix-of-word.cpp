class Solution {
public:
    string reversePrefix(string word, char ch) {

        int n = word.size();

        int ptr = 0;
        while(word[ptr] != ch){
            ptr++;
            if(ptr == n){
                return word;
            }
        }

        int stPtr = 0;
        while(stPtr < ptr){
            swap(word[stPtr++],word[ptr--]);
        }
        return word;
    }
};