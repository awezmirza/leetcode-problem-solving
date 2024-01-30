class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto el:tokens){
            if(el == "+" || el == "-" || el == "*" || el == "/"){
                int second = stoi(st.top());
                st.pop();
                int frst = stoi(st.top());
                st.pop();
                int num;

                if(el == "+") num = frst + second; 
                else if(el == "-") num = frst - second; 
                else if(el == "*") num = frst * second; 
                else num = frst / second;
                string numString = to_string(num);
                st.push(numString);
            }
            else st.push(el);
        }
        return stoi(st.top());
    }
};