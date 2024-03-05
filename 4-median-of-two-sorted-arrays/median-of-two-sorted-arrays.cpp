class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int st = 0;
        int end = m;
        while(st<=end){
            int leftSide = (st + end)/2;
            int rightSide = (m+n+1)/2 - leftSide;

            int x1 = (leftSide == 0) ? INT_MIN : nums1[leftSide - 1];
            int x2 = (rightSide == 0) ? INT_MIN : nums2[rightSide - 1];

            int x3 = (leftSide == m) ? INT_MAX : nums1[leftSide];
            int x4 = (rightSide == n) ? INT_MAX : nums2[rightSide];

            if(x1 <= x4 && x2 <= x3){
                if((m+n)%2 == 1){
                    return max(x1,x2);
                }
                else{
                    return (max(x1,x2) + min (x3,x4))/2.0;
                }
            }
            if(x1 > x4)
                end = leftSide - 1;
            else 
                st = leftSide + 1;
        }
        return -1;
    }
};