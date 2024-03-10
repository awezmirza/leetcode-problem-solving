class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int ptr1 = 0, ptr2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(ptr1 < n1 && ptr2 < n2){
            if(nums1[ptr1] == nums2[ptr2]){
                int toPush = nums1[ptr1];
                ans.push_back(toPush);
                while(ptr1 < n1 && nums1[ptr1] == toPush) ptr1++;
                while(ptr2 < n2 && nums2[ptr2] == toPush) ptr2++;
            }
            else if(nums1[ptr1] > nums2[ptr2])
                ptr2++;
            else 
                ptr1++;
        }
        return ans;
    }
};