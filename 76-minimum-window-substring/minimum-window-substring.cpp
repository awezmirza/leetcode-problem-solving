class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        int tmapCnt = 0;
        for(auto c : t){
            tmap[c]++;
            tmapCnt++;
        }
        int i = 0,j=0;
        int n = s.size();
        int ansStart = -1;
        int ansLength = INT_MAX;
        while(j<n){
            if(tmap[s[j]]>0) tmapCnt--;
            tmap[s[j]]--;
            if(tmapCnt == 0){
                
                while(tmapCnt == 0){
                    int len = j - i +1;
                    if(len<ansLength){
                        ansStart = i;
                        ansLength = len;
                    }
                    tmap[s[i]]++;
                    if(tmap[s[i]]>0) tmapCnt++;
                    i++;
                }
            }
            j++;
        }
        if(ansStart == -1) return "";
        return s.substr(ansStart,ansLength);
    }
};