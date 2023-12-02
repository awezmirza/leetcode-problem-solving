class Solution {
public:
    bool isPossible(vector<int>& freq, string str){
        vector<int> copyFreq = freq;

        for(auto el : str){
            if(copyFreq[el - 'a'] == 0) return 0;
            copyFreq[el - 'a']--;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26);
        for(auto el : chars){
            freq[el - 'a']++;
        }
        int ans = 0;
        for(auto str : words){
            if(isPossible(freq,str)){
                ans += str.size();
            }
        }
        return ans;
    }
};