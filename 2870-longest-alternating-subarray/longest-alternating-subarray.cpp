class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int i = 1;

        int curr = 1;

        int cnt = 1;
        while (i < n) {

            while (i < n && nums[i] - nums[i - 1] == curr) {
                cnt++;
                cout << "in for i = " << i << endl;
                i++;
                curr = -(curr);
            }

            ans = max(ans, cnt);

            cnt = 1;
            curr = 1;

            if (i < n && nums[i] - nums[i - 1] == curr) {
                curr = -1;
                cnt = 2;
                cout<<"in if i = " << i << endl;
            }
            i++;
        }

        ans = max(ans, cnt);

        return ans == 1 ? -1 : ans;
    }
};