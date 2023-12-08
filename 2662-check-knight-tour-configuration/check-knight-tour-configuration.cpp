class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0) return false;

        vector<vector <int>> mp(n*n,vector<int>(2));
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]][0] = i;
                mp[grid[i][j]][1] = j;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }


        for(auto elem : mp){
            cout<<elem[0]<<" ";
            cout<<elem[1]<<" ";
            cout<<"   ";
        }


        for(int i = 1;i<n*n;i++){
            if((abs(mp[i][0] - mp[i-1][0])) == 2 && (abs(mp[i][1] - mp[i-1][1])) == 1 ){
                continue;
            }
            else if((abs( mp[i][0] - mp[i-1][0] )) == 1 && (abs(mp[i][1] - mp[i-1][1])) == 2 ){
                continue;
            }
            else{
                cout<<"false for i="<<i;
                return false;
            }
        }
        return true;
    }
};