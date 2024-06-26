class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int ptr = happiness.size() - 1;
        for(int i = 0; i < k; i++){
            if(happiness[ptr] - i > 0){
                ans += happiness[ptr] - i;
            }
            ptr--;
        }
        return ans;
    }
};