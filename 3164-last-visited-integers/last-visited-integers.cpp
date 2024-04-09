class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int k = 0;
        int m = nums.size();
        
        for(int i = 0;i<m;i++){
            int num = nums[i];

            if(num == -1){
                if(k > 0 && nums[i - 1] == -1){
                    k++;
                }
                else{
                    k = 1;
                }
                int n = seen.size();
                if(k > n){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(seen[n - k]);
                }
            }
            else
                seen.push_back(num);
        }
        return ans;
    }
};