class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = 100000;
        for (int num : nums) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            mini = min(sum, mini);
        }
        return mini;
    }
};