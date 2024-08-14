class Solution {
public:

    int binSearch(vector<int>& nums, int i, int maxDist) {
        int start = i + 1;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while (start <= end) {
            if (nums[mid] - nums[i] > maxDist) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        return mid;
    }

    int solve(vector<int>& nums, int maxDist) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = binSearch(nums, i, maxDist);
            cnt += j - i;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int highest = nums.back() - nums[0];
        int lowest = 0;
        
        int result = 0;
        while (lowest <= highest) {
            int mid = (lowest + highest) / 2;
            int totalDistancesLessThanMid = solve(nums, mid);
            if (totalDistancesLessThanMid < k) {
                lowest = mid + 1;
            } else {
                result = mid;
                highest = mid - 1;
            }
        }
        
        return result;
    }
};