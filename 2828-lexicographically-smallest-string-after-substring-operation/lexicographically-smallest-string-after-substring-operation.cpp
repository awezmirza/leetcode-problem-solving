class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int ptr1 = 0;
        while(ptr1 < n && s[ptr1] == 'a'){
            ptr1++;
        }
        if(ptr1 == n) s[n-1] = 'z';
        while(ptr1 < n && s[ptr1] != 'a'){
            s[ptr1] = s[ptr1] - 1;
            ptr1++;
        }
        return s;
    }
};