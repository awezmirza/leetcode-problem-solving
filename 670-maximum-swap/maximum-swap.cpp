class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int i = 0;
        int n = numStr.size();
        bool flag = true;
        while (i < n && flag) {
            int rtBig = i;
            for (int a = i; a < n; a++) {
                if (numStr[rtBig] <= numStr[a]) {
                    rtBig = a;
                }
            }

            while (i < n && numStr[i] == numStr[rtBig]) {
                i++;
            }
            if (i < rtBig) {
                swap(numStr[i], numStr[rtBig]);
                flag = false;
            }
        }
        return stoi(numStr);
    }
};