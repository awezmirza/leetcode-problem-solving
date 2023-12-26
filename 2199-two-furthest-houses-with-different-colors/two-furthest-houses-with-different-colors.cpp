class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        for(int i= 0,j=n-1;i<n;++i,--j){
            if(colors[0] != colors[j]) return j;
            if(colors[n-1] != colors[i]) return n-1 - i;
        }
        return 0;
    }
};