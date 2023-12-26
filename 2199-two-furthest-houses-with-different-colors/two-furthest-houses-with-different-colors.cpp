class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int start = 0, end  = n-1;
        int maxi = 0;
        while(start<end){
            if(colors[start] != colors[end]){
                maxi = end - start;
                break;
            }
            end--;
        }
        start = 0, end  = n-1;
        while(start<end){
            if(colors[start] != colors[end]){
                maxi = max(maxi, end - start);
                break;
            }
            start++;
        }
        return maxi;
    }
};