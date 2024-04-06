class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')' && close < open)
                close++;
        }
        // o -> 2
        // c -> 2
        cout<<"Open: "<<open<<endl;
        cout<<"Close: "<<close<<endl;

        int currOpen = 0;
        int currClose = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && currOpen < open && currOpen < close){
                ans.push_back(s[i]);
                currOpen++;
            }
            else if (s[i] == ')' && currClose < close && currClose < currOpen){
                cout<<"Inside for i = "<<i<<endl;
                    ans.push_back(s[i]);
                    currClose++;
            }
            else if(s[i] != ')' && s[i] != '('){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};