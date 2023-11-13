class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c=='o' or c=='u' or c == 'A' or c == 'E' or c == 'I' or c=='O' or c=='U') return true;
        return false;
        
    }
    
    string sortVowels(string s) {
        vector<int> indexes;
        vector<char> chars;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                indexes.push_back(i);
                chars.push_back(s[i]);
            }
        }
         sort(chars.begin(),chars.end());

               for(int i = 0; i<indexes.size();i++){
                   s[indexes[i]] = chars[i];
               }
               return s;
    }
};