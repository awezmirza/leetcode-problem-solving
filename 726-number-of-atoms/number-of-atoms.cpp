class Solution {
public:
    string countOfAtoms(string formula) {


        int i = 0;
        int n = formula.size();

        stack<map<string, int>> st;

        map<string, int> firstMp;
        st.push(firstMp);

        while (i < n) {
            if (formula[i] == '(') {
                map<string, int> mp;
                st.push(mp);
                i++;
            } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                string element;
                element.push_back(formula[i++]);
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    element.push_back(formula[i++]);
                }

                // Make Seperate Function
                if (i < n && formula[i] >= '0' && formula[i] <= '9') {
                    string num;
                    num.push_back(formula[i++]);
                    while (i < n && formula[i] >= '0' && formula[i] <= '9') {
                        num.push_back(formula[i++]);
                    }
                    map<string, int> topMp = st.top();
                    st.pop();
                    int numInt = stoi(num);
                    topMp[element] += numInt;
                    st.push(topMp);
                } else {
                    map<string, int> topMp = st.top();
                    st.pop();
                    topMp[element] += 1;
                    st.push(topMp);
                }
            }
            else {
                    i++;
                    string num;
                    map<string, int> topMp = st.top();
                    st.pop();

                    if (i < n && formula[i] >= '0' && formula[i] <= '9') {
                        num.push_back(formula[i++]);
                        while (i < n && formula[i] >= '0' && formula[i] <= '9') {
                            num.push_back(formula[i++]);
                        }
                        int numInt = stoi(num);
                        for (auto el : topMp) {
                            topMp[el.first] *= numInt;
                        }
                    }


                    map<string, int> topBMp = st.top();
                    st.pop();
                    for (auto el : topMp) {
                        topBMp[el.first] += el.second;
                    }
                    st.push(topBMp);
            }
        }

        string ans = "";
        map<string, int> mainMp = st.top();
        for (auto el : mainMp) {
            ans += el.first;
            if (el.second > 1) {
                ans += (to_string(el.second));
            }
        }
        return ans;
    }
};