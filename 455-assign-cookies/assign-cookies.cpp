class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(s.begin(), s.end()), sort(g.begin(), g.end());
        int gSz = g.size(), sSz = s.size();
        int sPtr = 0, gPtr = 0;

        int count = 0;

        while (sPtr < sSz && gPtr < gSz) {
            if (s[sPtr] >= g[gPtr]) count++, gPtr++;
            sPtr++;
        }
        return count;
    }
};