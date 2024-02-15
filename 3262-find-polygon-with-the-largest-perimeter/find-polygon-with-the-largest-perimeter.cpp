class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = -1;
        long long perim = nums[0] + nums[1];
        for(int i = 2;i<n;i++){
            if(perim > nums[i]){
                ans = perim + nums[i];
            }
            perim += nums[i];
        }
        return ans;
    }
};