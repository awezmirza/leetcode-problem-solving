class Solution {
public:
    string removeStr(string& s, string& remove) {
        stack<char> st;

        for (auto ch : s) {
            if (ch == remove[1] && !st.empty() && st.top() == remove[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    string removeStrON(string& s, string& remove) {
        int i = 0, j = 0;
        int len = s.length();
        while(j < len) {
            s[i] = s[j];
            i++;
            if(i > 1 && s[i - 2] == remove[0] && s[i - 1] == remove[1]) {
                i -= 2;
            }            
            j++;
        }
        while(i < len) {
            s.pop_back();
            i++;
        } 
        return s;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int len = s.length();

        string maxStr = x > y ? "ab" : "ba";
        string minStr = x < y ? "ab" : "ba";

        // Max
        string afterMax = removeStrON(s, maxStr);
        int afterMaxLen = afterMax.length();
        ans = ((len - afterMaxLen) / 2) * max(x, y);

        // Min
        string afterMin = removeStrON(afterMax, minStr);
        ans += (((afterMaxLen - afterMin.length()) / 2) * min(x, y));

        return ans;
    }
};