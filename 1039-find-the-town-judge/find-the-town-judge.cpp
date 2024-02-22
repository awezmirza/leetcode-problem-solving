class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> isJudge(n + 1,true);
        vector<int> isKnownBy(n + 1,0);
        for(vector<int>& tr:trust){
            isJudge[tr[0]] = false;
            isKnownBy[tr[1]]++;
        }
        for(int i = 1; i<=n;i++){
            if(isJudge[i] && isKnownBy[i] == n-1) return i;
        }
        return -1;
    }
};