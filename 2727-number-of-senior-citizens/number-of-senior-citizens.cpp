class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto str : details) {
            string age = str.substr(11, 2);
            int ageInInt = stoi(age);
            if (ageInInt > 60) {
                ans++;
            }
        }
        return ans;
    }
};