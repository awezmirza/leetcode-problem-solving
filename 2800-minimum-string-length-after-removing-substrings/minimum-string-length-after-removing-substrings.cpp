class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (char cur_char : s) {
            if (stack.empty()) {
                stack.push(cur_char);
                continue;
            }

            if (cur_char == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (cur_char == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(cur_char);
            }
        }

        return stack.size();
    }
};