class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while(i<n){
            int curr = nums[i];
            int cnt = 1;
            i++;
            while(i<n && nums[i] == curr){
                i++;
                cnt++;
            }
            if(cnt == 1){
                return -1;
            }
            cout<<"cnt: "<<cnt<<endl;
            if(cnt % 3 != 1 ){
                ans += cnt/3;
                cnt = cnt % 3;
            }
            else{
                ans += cnt/3;
                ans--;
                cnt = cnt % 3;
                cnt += 3;
            }
            ans += cnt/2;
            cnt = cnt % 2;
            cout<<"cnt after 2: "<<cnt<<endl;
            if(cnt>0){
                return -1;
            }
        }
        return ans;
    }
};