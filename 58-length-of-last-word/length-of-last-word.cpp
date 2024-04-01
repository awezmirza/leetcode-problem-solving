class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ptr = n-1;
        while(ptr>=0 && s[ptr] == ' '){
            ptr--;
        }
        int ans = 0;
        while(ptr>=0 && s[ptr] != ' '){
            ans++;
            ptr--;
        }
        return ans;
    }
};