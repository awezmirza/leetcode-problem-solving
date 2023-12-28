class Solution {
public:
    int minSteps(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        vector<int> sFreq(26, 0);
        // vector<int> tFreq(26, 0);
        int ans = 0;
        for(auto el : s){
            sFreq[el - 'a']++;
        }
        for(auto el : t){
            sFreq[el - 'a']--;
        }
        for(auto el : sFreq){
            if(el > 0){
                ans+= el;
            }
        }
        return ans;
    }
};