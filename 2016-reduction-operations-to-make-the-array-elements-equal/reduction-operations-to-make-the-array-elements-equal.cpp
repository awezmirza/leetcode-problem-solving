class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <int> occurrence;
        int counter = 0;
        occurrence.push_back(0);
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]) counter++;
            occurrence.push_back(counter);
        }
        int ans = accumulate(occurrence.begin(),occurrence.end(),0);
        return ans;
    }
};