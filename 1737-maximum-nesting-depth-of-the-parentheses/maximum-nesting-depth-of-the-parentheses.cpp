class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int currCnt = 0;
        for(char ch:s){
            if(ch == '('){
                currCnt++;
            }
            else if(ch == ')'){
                ans = max(ans, currCnt);
                currCnt--;
            }
        }
        return ans;
    }
};