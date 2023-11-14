class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set <string> ansSet;
        vector <int> left(26),right(26);
        int n = s.size();
        for(int i = 0;i<n;i++){
            right[ s[i] - 'a']++;
        }
        for(int i = 0;i<n-1;i++){
            right[s[i]- 'a']--;
            for(int j = 0;j<26;j++){
                if(left[j] >0 && right[j] > 0 ){
                    char temp = 'a' + j;
                    string pal = "";
                    pal += temp;
                    pal += s[i];
                    pal += temp;
                    ansSet.insert(pal);
                }
            }
            left[s[i] - 'a']++;
        }
        return ansSet.size();
    }
};
