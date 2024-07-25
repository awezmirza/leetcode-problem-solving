class Solution {
public:

    void merge(vector<int>& nums, int start, int end) {
        int mid =  (start + end) / 2; 

        int len1 = mid - start + 1;
        int len2 = end - mid;

        vector<int> arr1(nums.begin() + start, nums.begin() + start + len1);
        vector<int> arr2(nums.begin() + mid + 1, nums.begin() + end + 1);

        int ptr1 = 0;
        int ptr2 = 0;

        while (ptr1 < len1 && ptr2 < len2) {
            if (arr1[ptr1] < arr2[ptr2]) {
                nums[start] = arr1[ptr1++];
            } else {
                nums[start] = arr2[ptr2++];
            }
            start++;
        }

        while (ptr1 < len1) {
            nums[start++] = arr1[ptr1++];
        }

        while (ptr2 < len2) {
            nums[start++] = arr2[ptr2++];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = (start + end) / 2; 

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};