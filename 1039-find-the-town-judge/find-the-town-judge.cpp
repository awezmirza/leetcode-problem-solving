class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<bool,int>> isJudge(n,{true,0});
        for(vector<int>& tr:trust){
            isJudge[tr[0]-1].first = false;
            isJudge[tr[1]-1].second++;
        }
        for(int i = 0; i<n;i++){
            if(isJudge[i].first && isJudge[i].second == n-1) return i+1;
        }
        return -1;
    }
};