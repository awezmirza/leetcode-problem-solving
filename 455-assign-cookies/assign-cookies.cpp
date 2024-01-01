class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int gSz = g.size();
        int sSz = s.size();
        int count = 0;
        for(int i = 0,gPtr = 0;i<sSz && gPtr < gSz;i++){
            if(s[i] >= g[gPtr]){
                count++;
                gPtr++;
            }
        }
        return count;
    }
};