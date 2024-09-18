class Solution {
public:

    static bool customSort(string a, string b) {
        string s1 = a + b;
        string s2 = b + a;
        return s1 > s2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numStr;
        for (auto num : nums) {
            numStr.push_back(to_string(num));
        }
        sort(numStr.begin(), numStr.end(), customSort);
        string ans = "";
        int n = nums.size();
        if (numStr[0] == "0") {
            return "0";
        }
        for (int i = 0; i < n; i++) {
            ans += numStr[i];
        }
        return ans;
    }
};