class Solution {
    
public:
    bool canTake(string arr,vector<bool>& freq){
        for(int i = 0;i<arr.size();i++){
            char ch = arr[i];
            if(freq[ch - 'a']){
                remove(arr.substr(0,i),freq);
                return false;
            }
            freq[ch - 'a'] = true;
        }
        return true;
    }

    void remove(string arr,vector<bool>& freq){
        for(char ch:arr){
            freq[ch - 'a'] = false;
        }
    }

    int solve(vector<string>& arr,vector<bool>& freq,int curr,int length){
        if(curr >= arr.size()){
            return length;
        }
        int taking;
        if(canTake(arr[curr],freq)){
            taking = solve(arr,freq,curr+1,length+arr[curr].size());
            remove(arr[curr],freq);
        }
        int woTaking=solve(arr,freq,curr+1,length);
        return max(taking,woTaking);
    }

    int maxLength(vector<string>& arr) {
        vector<bool> freq(26,0);
        int ans = solve(arr,freq,0,0);
        return ans;
    }
};