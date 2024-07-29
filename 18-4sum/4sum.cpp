class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                while (i < n && nums[i - 1] == nums[i]) {
                    i++;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1) {
                    while (j < n && nums[j-1] == nums[j]) {
                        j++;
                    }
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    if ((long) nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    } else if ((long) nums[i] + nums[j] + nums[k] + nums[l] < target) {
                        k++;
                    } else {
                        l--;
                    }
                } 
            }
        }
        return ans;
    }
};