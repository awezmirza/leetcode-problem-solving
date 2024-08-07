class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<pair<int, string>> mp = { {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"} };
        
        string ans = "";
        for (auto pr : mp) {
            if (num >= pr.first) {  
                int b = num / pr.first;
                string before;
                if (num >= 100) {
                    before = numberToWords(b);
                    if (ans == "") {
                        ans += before + " " + pr.second;
                    } else {
                        ans += " " + before + " " + pr.second;
                    }
                } else {
                    if (ans == "") {
                        ans += pr.second;
                    } else {
                        ans += " " + pr.second;
                    }
                }
                num = num % pr.first;
            }
        }
        return ans;
    }
};