class Solution {
public:

    bool isPossible(vector<int>& nums, int& mid,int p){
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i] - nums[i-1] <= mid){
                p--;
                i++;
            }
            if(p==0) return true;
        }
        return false;
    }

    int binSrch(int s, int e,vector<int>& nums,int p){
        int ans = 0;
        int n = nums.size();
        int mid= s+((e-s)>>1);
        while(s<=e){
            if(isPossible(nums,mid,p)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid= s+((e-s)>>1);
        }
        return ans;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int maxDiff = nums[nums.size() - 1] - nums[0];
        return binSrch(0,maxDiff,nums,p);
    }
};