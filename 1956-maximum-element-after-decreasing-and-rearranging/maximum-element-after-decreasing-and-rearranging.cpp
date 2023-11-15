class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prev = 0;
        for(int& elem : arr){
            elem = min(prev+1,elem);
            prev = elem;
        }
        return arr[arr.size() - 1];
    }
};