class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0;
        int closeCount = 0;
        int n = s.size();
        for (char ch : s) {
            if (ch == '(')
                openCount++;
            else if (ch == ')' && closeCount < openCount)
                closeCount++;
        }

        int currOpenCount = 0;
        int currCloseCount = 0;
        string ans = "";
        for (char ch : s) {
            if (ch == '(' && currOpenCount < closeCount){
                ans.push_back(ch);
                currOpenCount++;
            }
            else if (ch == ')' && currCloseCount < currOpenCount){
                ans.push_back(ch);
                currCloseCount++;
            }
            else if(ch != ')' && ch != '('){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};