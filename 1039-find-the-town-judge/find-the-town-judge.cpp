class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> isJudge(n,true);
        vector<int> isKnownBy(n,0);
        for(vector<int>& tr:trust){
            isJudge[tr[0]-1] = false;
            isKnownBy[tr[1]-1]++;
        }
        for(int i = 0; i<n;i++){
            if(isJudge[i] && isKnownBy[i] == n-1) return i+1;
        }
        return -1;
    }
};