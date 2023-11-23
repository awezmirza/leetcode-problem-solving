class Solution {
public:

    bool isArithmetic(vector<int>& currNums){
        int n = currNums.size();
        if(n<=2) return true;
        sort(currNums.begin(),currNums.end());
        int diff = currNums[1] - currNums[0];
        for(int i = 2; i<n;i++){
            if(currNums[i] - currNums[i-1] != diff) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = r.size();
        vector<bool> ans;
        // O(m)
        for(int i = 0;i<m;i++){
            // O(n)
            vector<int> currNums(nums.begin() + l[i], nums.begin() + r[i] + 1);
            // O(n log n)
            ans.push_back(isArithmetic(currNums));
        }
        return ans;
    }
};