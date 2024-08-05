class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
            } else {
                if (mp[arr[i]] != -1) {
                    int prevIdx = mp[arr[i]];
                    arr[prevIdx] = "";
                }
                arr[i] = "";
            }
        }
        for (auto str : arr) {
            if (str != "") {
                k--;
            }

            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};