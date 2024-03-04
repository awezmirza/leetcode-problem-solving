class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = tokens.size()-1;
        int score = 0, mxScore = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                i++;
                score++;
                mxScore = max(score, mxScore);
            }
            else if(score > 0){
                power += tokens[j];
                score--, j--;
            }
            else break;
        }
        return mxScore;
    }
};