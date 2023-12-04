class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int large = 0;
        string ans = "";
        for(int i=0;i<n-2;i++){
            if(num[i] > large && num[i] == num[i + 1] && num[i] == num[i+2]){
                ans = "";
                large = num[i];
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                i += 2;
            }
        }
        return ans;
    }
};