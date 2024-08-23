class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 0;
        
        int i = 0;
        int n = expression.size();
        while (i < n) {
            string currNumStr = "";
            string currDenStr = "";
            while (i < n && expression[i] != '/') {
                currNumStr.push_back(expression[i]);
                i++;
            }
            i++;
            while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                currDenStr.push_back(expression[i]);
                i++;
            }

            int currNum = stoi(currNumStr);
            int currDen = stoi(currDenStr);

            if (numerator == 0) {
                numerator = currNum;
                denominator = currDen;
            } else {
                numerator = (numerator * currDen) + (denominator * currNum);
                denominator = currDen * denominator;
            }
        }

        if (numerator == 0) {
            return "0/1";
        }

        int gcd = __gcd(abs(numerator), abs(denominator));
        return to_string(numerator/gcd) + "/" + to_string(denominator/gcd);
    }
};