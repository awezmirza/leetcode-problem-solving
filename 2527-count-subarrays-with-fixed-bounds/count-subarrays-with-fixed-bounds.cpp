class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minFnd = -1;
        int maxFnd = -1;
        long long ans = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == minK ){
                minFnd = i;
            }
            if(nums[i] == maxK){
                maxFnd = i;
            }
            if(nums[i] > maxK || nums[i] < minK){
                maxFnd = -1;
                minFnd = -1;
                j = i+1;
            }
            if(minFnd!=-1 && maxFnd!=-1){
                cout<<"in for i:"<<i<<endl;
                if(minFnd > maxFnd){
                    int toSub = i - maxFnd;
                    ans += (i-j+1) - toSub;
                }
                else{
                    int toSub = i - minFnd;
                    ans += (i-j+1) - toSub;
                }
            }
        }
        return ans;
    }
};