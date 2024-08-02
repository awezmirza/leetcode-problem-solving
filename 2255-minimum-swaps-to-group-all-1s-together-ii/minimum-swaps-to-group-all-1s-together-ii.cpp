class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalNumberOfOnes = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            totalNumberOfOnes += nums[i];
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

        while (i < n) {
            if (j >= n) {
                j = 0;
            }
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