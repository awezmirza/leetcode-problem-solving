class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt = 0;
        // 0 -> 0
        // 1 -> 1
        // 2 -> 0
        // 3 -> 1
        for(int i=0;i<n;i++){
            if( i%2 == 0){ //even
                if(s[i] == '1') cnt++;
            }
            else{
                if(s[i] == '0') cnt++;
            }
        }
        return min(cnt , n - cnt );
    }
};