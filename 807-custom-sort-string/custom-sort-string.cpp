class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        for(auto c:s){
            freq[c - 'a']++;
        }
        string ans = "";
        for(auto c:order){
            while(freq[c-'a']){
                ans.push_back(c);
                freq[c-'a']--;
            }
        }
        for(int i = 0;i<26;i++){
            while(freq[i]){
                cout<<"in";
                ans.push_back(i + 'a');
                freq[i]--;
            }
        }
        return ans;
    }
};