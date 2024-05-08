class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> freq(1000001, -1);
        int n = score.size();
        for(int i = 0; i < n; i++){
            freq[score[i]] = i;
        }

        vector<string> ans(n);

        int counter = 1;
        for(int i = 1000000; i >= 0; i--){
            if(freq[i] > -1){
                if(counter == 1){
                    ans[freq[i]] = "Gold Medal";
                }
                else if(counter == 2){
                    ans[freq[i]] = "Silver Medal";
                }
                else if(counter == 3){
                    ans[freq[i]] = "Bronze Medal";
                }
                else{
                    ans[freq[i]] = to_string(counter);
                }
                counter++;
            }
        }
        return ans;
    }
};