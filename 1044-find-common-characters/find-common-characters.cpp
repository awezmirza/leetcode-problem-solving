class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i = 0; i < n; i++){
            for(char ch : words[i]){
                freq[i][ch - 'a']++;
            }
        }

        vector<string> ans;

        for(auto ch : words[0]){

            bool notFound = 0;
            for(int i = 0; i < n; i++){
                if(freq[i][ch - 'a'] == 0){
                    notFound = true;
                    break;
                }
                freq[i][ch - 'a']--;
            }

            if(!notFound){
                string toPush;
                toPush += ch;
                ans.push_back(toPush);
            }

        }
        return ans;

    }
};