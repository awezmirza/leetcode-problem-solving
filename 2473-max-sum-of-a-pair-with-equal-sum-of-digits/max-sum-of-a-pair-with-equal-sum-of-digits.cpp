class Solution {

    int numToDig(int num) {
        if (num < 10) {
            return num;
        }

        int ans = 0;

        while (num) {
            ans += (num % 10);
            num /= 10;
        }

        return ans;
    }

    int twoMaxiSum(vector<int> nums) {
        int maxi = 0;
        int secondMaxi = 0;

        for (int num : nums) {
            if (num > maxi) {
                secondMaxi = maxi;
                maxi = num;
            } else if (num > secondMaxi) {
                secondMaxi = num;
            }
        }

        return maxi + secondMaxi;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int num : nums) {
            int dig = numToDig(num);
            mp[dig].push_back(num);
        }

        int ans = -1;
        for (auto pr : mp) {
            auto vec = pr.second;
            if (vec.size() > 1) {
                ans = max(ans, twoMaxiSum(vec));
            }
        }

        return ans;
    }
};