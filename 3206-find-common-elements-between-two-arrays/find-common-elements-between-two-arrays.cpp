class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> freq1(101,false);
        vector<bool> freq2(101,false);
        int occ1 =0; 
        int occ2 =0; 
        for(auto num:nums1){
            freq1[num] = true;
        }
        for(auto num:nums2){
            if(freq1[num]) occ2++;
            freq2[num] = true;
        }
        for(auto num:nums1) if(freq2[num]) occ1++;
        return {occ1,occ2};
    }
};