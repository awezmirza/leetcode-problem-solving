class Solution {
public:

    int findMapping(int num, vector<int>& mapping) {
        string res;
        if (num == 0) {
            res.push_back(mapping[0] + '0');
        } else {
            while (num) {
                int x = num % 10;
                res.push_back(mapping[x] + '0');
                num = num / 10;
            }
        } 
        reverse(res.begin(), res.end());
        int resNum = stoi(res);
        return resNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        map<int, vector<int>> fnd;
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int res = findMapping(num, mapping);
            fnd[res].push_back(num);
        }

        vector<int> ans;

        for (auto m : fnd) {
            for (int nu : m.second) {
                ans.push_back(nu);
            }
        }

        return ans;
    }
};