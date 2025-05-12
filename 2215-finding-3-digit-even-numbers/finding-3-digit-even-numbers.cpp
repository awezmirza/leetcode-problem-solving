class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] != 0) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        for (int k = 0; k < n; k++) {
                            if (i != k && j != k && (digits[k] % 2 == 0)) {
                                ans.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                            }
                        }
                    }
                }
            }
        }

        vector<int> vec;

        for (auto num : ans) {
            vec.push_back(num);
        }

        return vec;
    }
};