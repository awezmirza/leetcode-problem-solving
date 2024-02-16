class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> freqs;
        int i = 0;
        while (i < n) {
            int cnt = 1;
            int last = arr[i++];
            while (i < n && arr[i] == last) {
                cnt++;
                i++;
            }
            freqs.push_back(cnt);
        }
        sort(freqs.begin(), freqs.end(), greater());
        while (k > 0 && freqs.size() > 0) {
            int iterator = freqs.size() - 1;
            if (freqs[iterator] > k) {
                freqs[iterator] = freqs[iterator] - k;
                k = 0;
            } else {
                k = k - freqs[iterator];
                freqs.pop_back();
            }
        }
        return freqs.size();
    }
};