class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            if( mp.find(s[i] - 'a') == mp.end() ){
                mp[s[i] - 'a'] = i;
            } 
            else{
                ans = max( ans, i - mp[s[i] - 'a'] -1 );
            }
        }

        return ans;
    }
};