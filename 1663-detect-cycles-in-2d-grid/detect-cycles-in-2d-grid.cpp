class Solution {
private:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
public:
    bool dfs(int x,int y,int xp, int yp,vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xf=x+dx[i];
            int yf=y+dy[i];
            if(xf<n && yf<m && xf>=0 && yf>=0 && grid[xf][yf]==grid[x][y] && !(xf==xp && yf==yp)){
                if(vis[xf][yf]!=0){
                    return true;
                }
                else{
                    if(dfs(xf,yf,x,y,vis,grid)){
                        return true;
                    }
                }
            }
        }
        vis[x][y]=2;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    if(dfs(i,j,-1,-1,vis,grid)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};