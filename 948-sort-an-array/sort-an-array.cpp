class Solution {
public:
    void merge(vector<int>& arr,int start,int end){
        int mid = (start + end )>>1;
        int len1 = mid-start+1;
        int len2 = end-mid;

        vector<int> left;
        vector<int> right;

        int k = start;
        for(int i = 0;i<len1;k++,i++){
            left.push_back(arr[k]);
        }
        k = mid + 1;
        for(int i = 0;i<len2;k++,i++){
            right.push_back(arr[k]);
        }
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1<len1 && ptr2 < len2){
            if(left[ptr1]<right[ptr2]){
                arr[start] = left[ptr1];
                start++,ptr1++;
            }
            else{
                arr[start] = right[ptr2];
                start++,ptr2++;
            }
        }
        while(ptr1<len1){
            arr[start] = left[ptr1];
            start++,ptr1++;
        }
        while(ptr2<len2){
            arr[start] = right[ptr2];
            start++,ptr2++;
        }

    }

    void mergeSort(vector<int>& arr,int start,int end){
        if(start >= end ){
            return;
        }
        int mid = (start + end)>>1;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};