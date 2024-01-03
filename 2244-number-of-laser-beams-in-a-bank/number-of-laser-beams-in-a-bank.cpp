class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevRow = 0;
        for(auto str : bank){
            int currRow = 0;
            for(auto el : str){
                if(el == '1') currRow++;
            }
            if(currRow > 0){
                ans+= currRow * prevRow;
                prevRow = currRow;
            }
        }
        return ans;
    }
};