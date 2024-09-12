class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int hash = 0;
        for (auto allowedChar : allowed) {
            int temp = 1;
            temp <<= allowedChar - 'a';
            hash |= temp;
        }

        int count = 0;
        for (string word : words) {
            bool flag = false;
            for (char letter : word) {
                int temp = 1 << (letter - 'a');
                if ((hash & temp) != temp) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                count++;
            }
        }
        return count;
    }
};