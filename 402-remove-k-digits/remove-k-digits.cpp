class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int it = 0;
        int n = num.size();
        while (it < n){
            char el = num[it];
            if(ans.size() > 0 && ans.back() > el && k > 0){
                ans.pop_back();
                k--;
            }
            else{
                ans.push_back(el);
                it++;
            }
        }
        while (k){
            ans.pop_back();
            k--;
        }

        it = 0;
        while (it < ans.size() && ans[it] == '0'){
            it++;
        }
        ans = ans.substr(it, ans.size() - it);

        if (ans == ""){
            return "0";
        }
        return ans;
    }
};