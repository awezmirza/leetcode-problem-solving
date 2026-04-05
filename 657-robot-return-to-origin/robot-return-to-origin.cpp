class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> coord(2, 0);
        for (char c : moves) {
            if (c == 'U') {
                coord[1]--;
            } else if (c == 'D') {
                coord[1]++;
            } else if (c == 'L') {
                coord[0]--;
            } else {
                coord[0]++;
            } 
        }

        return coord[0] == 0 && coord[1] == 0;
    }
};