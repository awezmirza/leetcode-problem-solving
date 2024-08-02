class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalNumberOfOnes = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1){
                totalNumberOfOnes++;
            }
        }

        int ans = n;

        int i = 0, j = 0;
        int zeroesInRange = 0;
        while (j < totalNumberOfOnes) {
            if (nums[j] == 0) {
                zeroesInRange++;
            }
            j++;
        }

        while (j < n) {
            ans = min(ans, zeroesInRange);
            if (nums[i] == 0) {
                zeroesInRange--;
            }
            if (nums[j] == 0) {
                zeroesInRange++;
            }
            j++, i++;
        }

        j = 0;
        while (i < n) {
            ans = min(ans, zeroesInRange);
            if (nums[i] == 0) {
                zeroesInRange--;
            }
            if (nums[j] == 0) {
                zeroesInRange++;
            }
            j++, i++;
        }

        return ans;

    }
};