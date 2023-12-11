class Solution {
public:

    bool binSrch(int elem, vector<int>& arr, int& criteria){
        int start = 0;
        int end = arr.size();
        int mid = start + ((end - start)>>1);

        int binSrchAns;
        while(start<=end){
            if(arr[mid] == elem){
                binSrchAns = mid;
                end = mid-1;
            }
            else if(arr[mid] > elem){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
            mid = start + ((end - start)>>1);
        }
        if(arr[binSrchAns] == arr[binSrchAns + criteria]){
            return true;
        }
        return false;
    }

    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int criteria = n/4;
        vector<int> possibleAns{ arr[n/4],arr[n/2],arr[3*n/4]};

        for(int elem : possibleAns){
            if(binSrch(elem, arr, criteria)){
                return elem;
            } 
        }
        return 0;
    }
};