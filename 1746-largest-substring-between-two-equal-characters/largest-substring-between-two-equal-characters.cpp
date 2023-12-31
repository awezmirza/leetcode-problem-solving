class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        
        vector<vector<int>> mp (26, vector<int> (2,0));

        for(int i = 0;i<n;i++){
            if( mp[s[i] - 'a'][0] == 0 ){
                mp[s[i] - 'a'][0] = 1;
                mp[s[i] - 'a'][1] = i;
            } 
            else{
                ans = max( ans, i - mp[s[i] - 'a'][1] -1 );
            }
        }

        return ans;
    }
};