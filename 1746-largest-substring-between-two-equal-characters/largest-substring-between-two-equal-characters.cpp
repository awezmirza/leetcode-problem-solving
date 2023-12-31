class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        
        vector<pair <int,int>> mp (26, {0,0});

        for(int i = 0;i<n;i++){
            if( mp[s[i] - 'a'].first == 0 ){
                mp[s[i] - 'a'].first = 1;
                mp[s[i] - 'a'].second = i;
            } 
            else{
                ans = max( ans, i - mp[s[i] - 'a'].second -1 );
            }
        }

        return ans;
    }
};