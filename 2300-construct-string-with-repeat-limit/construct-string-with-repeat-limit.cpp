class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;
        bool used = true;
        bool repeated = false;
        int ptr = 25;

        while (used && ptr >=0) {
            if (!repeated) {
                int cycle = min(repeatLimit, freq[ptr]);
                for (int i = 0; i < cycle; i++) {
                    ans.push_back(ptr + 'a');
                }
                freq[ptr] -= cycle;
                if (freq[ptr] != 0) {
                    repeated = true;
                } else {
                    ptr--;
                }
            } else {
                int toFind = ptr - 1;
                used = false;
                while (toFind >= 0 && !used) {
                    if (freq[toFind] > 0) {
                        ans.push_back(toFind + 'a');
                        freq[toFind]--;
                        used = true;
                        repeated = false;
                    }
                    toFind--;
                }
            }
        }
        return ans;
    }
};