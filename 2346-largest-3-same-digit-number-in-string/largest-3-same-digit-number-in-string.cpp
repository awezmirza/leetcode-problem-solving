class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "0";
        for(int i=0;i<n-2;i++){
            if(num[i] >= ans[0] && num[i] == num[i + 1] && num[i] == num[i+2]){
                ans = "";
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                i += 2;
            }
        }
        return ans == "0" ? "":ans ;
    }
};