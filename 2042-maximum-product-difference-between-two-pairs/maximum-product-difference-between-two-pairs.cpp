class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        
        int largest = 0;
        int large = 0;
        int small = 100000;
        int smallest = 100000;

        for(int i = 0;i<n;++i){
            if(nums[i] >= largest){
                large = largest;
                largest = nums[i];
            }
            else if(nums[i] >= large){
                large = nums[i];
            }

            if(nums[i] <= smallest){
                small = smallest;
                smallest = nums[i];
            }
            else if(nums[i] <= small){
                small = nums[i];
            }
        }

        return (large*largest) - (small*smallest);
    }
};