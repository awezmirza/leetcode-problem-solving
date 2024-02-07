class Solution {
public:

    void rotate(vector<int>& nums){
        int temp = nums[0];
        int n = nums.size();
        for(int i = 0;i<n - 1;i++){
            nums[i] = nums[i+1];
        }
        nums[n-1] = temp;
    }

    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long cost = LONG_MAX;
        vector<int> minCost(n,INT_MAX);

        for(int i = 0;i<n;i++){
            if(i!=0){
                rotate(nums);
            }
            long long currCost = 0;
            for(int j=0;j<n;j++){
                minCost[j] = min(minCost[j],nums[j]);
                currCost += minCost[j];
            }
            currCost += (long long) i*x;
            cost = min(cost,currCost);
        }
        return cost;
    }
};