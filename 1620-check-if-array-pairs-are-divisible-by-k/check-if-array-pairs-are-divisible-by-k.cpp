class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            int currRem = num % k;
            if (currRem < 0) {
                currRem += k;
            }
            int toFind = (k - currRem) % k;
            if (mp[toFind] > 0) {
                mp[toFind]--;
            } else {
                mp[currRem]++;
            }
        }
        for (auto pr : mp) {
            if (pr.second > 0) {
                
                return false;
            }
        }
        return true;
    }
};