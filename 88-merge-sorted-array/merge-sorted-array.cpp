class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> ans(m + n);
        int ansPtr = 0;
        while (ptr1 < m && ptr2 < n) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ans[ansPtr++] = nums1[ptr1++];
            } else {
                ans[ansPtr++] = nums2[ptr2++];
            }
        }
        while (ptr1 < m) {
            ans[ansPtr++] = nums1[ptr1++];
        }
        while (ptr2 < n) {
            ans[ansPtr++] = nums2[ptr2++];
        }
        nums1 = ans;
    }
};