class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ptr1 = 0;
        int ptr2 = 0;

        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> ans;

        while(ptr1 < sz1 && ptr2 < sz2){
            if(nums1[ptr1] == nums2[ptr2]){
                ans.push_back(nums1[ptr1]);
                ptr1++, ptr2++;
            }
            else if(nums1[ptr1] < nums2[ptr2]){
                ptr1++;
            }
            else{
                ptr2++;
            }
        }

        return ans;
    }
};