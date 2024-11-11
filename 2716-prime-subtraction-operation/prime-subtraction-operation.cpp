class Solution {
public:
    void fillWithSieve(vector<bool>& isPrime) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < 1001; i++) {
            if (isPrime[i]) {
                int j = i * i;
                while (j < 1001) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<bool> isPrime(1001, true);
        fillWithSieve(isPrime);
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
            } else {
                int sub = nums[i] - nums[i + 1] + 1;
                bool fnd = false;
                for (int j = sub; j < nums[i] && !fnd; j++) {
                    if (isPrime[j]) {
                        nums[i] -= j;
                        fnd = true;
                    }
                }
                if (!fnd) {
                    return false;
                }
            }
        }
        return true;
    }
};