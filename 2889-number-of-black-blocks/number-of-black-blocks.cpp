class Solution 
{
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) 
    {
        map<pair<int,int>,int> mp;
        for(auto coordinate: coordinates)
        {
            int r=coordinate[0], c=coordinate[1];
            if(r-1>=0 && c-1>=0) mp[{r-1,c-1}]++;
            if(r-1>=0 && c+1<n) mp[{r-1,c}]++;
            if(r+1<m && c-1>=0) mp[{r,c-1}]++;
            if(r+1<m && c+1<n) mp[{r,c}]++;
        }
        vector<long long> ans(5,0);
        for(auto it: mp) if(it.second<5) ans[it.second]++;
        long long ans0=(long long)(m-1)*(n-1)-(long long)accumulate(ans.begin(),ans.end(),(long long)0);
        ans[0]=ans0;
        return ans;
    }
};