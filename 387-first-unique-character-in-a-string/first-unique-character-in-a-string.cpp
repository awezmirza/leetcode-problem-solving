class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        int n = s.size();
        for(char el : s){
            freq[el - 'a']++;
        }
        for(int i = 0;i<n;i++){
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};