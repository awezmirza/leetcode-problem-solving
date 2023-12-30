class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);
        int n = words.size();
        for(auto word : words){
            for(auto letter : word){
                freq[letter - 'a']++;
            }
        }
        for(auto el : freq){
            if(!(el == 0 || ( el%n == 0 )))
            return false;
        }
        return true;
    }
};