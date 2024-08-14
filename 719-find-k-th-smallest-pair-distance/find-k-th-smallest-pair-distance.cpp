class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> allDists(maxEl + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(nums[i] - nums[j]);
                allDists[dist]++;
            }
        }
        for (int i = 0; i < maxEl + 1; i++) {
            k -= allDists[i];
            if (k <= 0) {
                return i;
            }
        }
        return 0;
    }
};