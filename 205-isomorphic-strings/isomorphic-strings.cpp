// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char,char> mp;
//         vector<bool> used(256);
//         int n = s.size();
//         for(int i = 0;i<n;i++){
//             if(mp.count(s[i])){

//                 return false;
//             }
//             else{
//                 mp[t[i]] = s[i];
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arrs[256] = {0};
        bool arrt[256] = {0};
        for(int i=0;i<s.size();i++){
            if(arrs[s[i]] == 0 && arrt[t[i]] == 0 ){
            arrs[s[i]] = t[i];
            arrt[t[i]] = 1;
            }
        }
        for(int i=0;i<s.size();i++){
            if(arrs[s[i]] != t[i]){
            return false;
            }
        }
        return true;
    }
};
