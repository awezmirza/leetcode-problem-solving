class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> arr;
        int k = nums.size();
        for (int i = 0; i < k; i++) {
            for (auto num : nums[i]) {
                arr.push_back({num, i});
            }
        }
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        unordered_set<int> st;
        vector<int> cnt(k, 0);
        int i = 0;
        int j = 0;
        for (auto el : arr) {
            cout<<"{"<<el.first<<","<<el.second<<"}"<<" ";
        }
        while (j < n && st.size() != k) {
            st.insert(arr[j].second);
            cnt[arr[j].second]++;
            j++;
        }
        // cout<<"\n"<<j;
        bool allSet = true;

        vector<int> ans = {arr[0].first, arr[j - 1].first};
        while (i < n) {
            if (allSet) {
                vector<int> currAns = {arr[i].first, arr[j - 1].first};
                int c = ans[0];
                int d = ans[1];
                int a = currAns[0];
                int b = currAns[1];
                if ((b - a < d - c) || ((b - a == d - c) && a < c)) {
                    ans = currAns;
                }
                i++;
                cnt[arr[i - 1].second]--;
                if (cnt[arr[i - 1].second] == 0) {
                    allSet = false;
                }
            } else {
                if (j == n) {
                    break;
                }
                if (cnt[arr[j].second] == 0) {
                    allSet = true;
                }
                cnt[arr[j].second]++;
                j++;
            }
        }

        return ans;
    }
};