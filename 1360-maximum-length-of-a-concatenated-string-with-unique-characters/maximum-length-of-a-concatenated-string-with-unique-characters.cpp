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

    void solve(vector<string>& arr, int& ans,vector<bool>& freq,int curr,int length){
        if(curr >= arr.size()){
            ans = max(ans,length);
            return;
        }

        if(canTake(arr[curr],freq)){
            cout<<"Taking: "<<arr[curr]<<endl;
            cout<<"len: "<<length+arr[curr].size()<<endl;
            solve(arr,ans,freq,curr+1,length+arr[curr].size());
            cout<<"Removing: "<<arr[curr]<<endl;
            remove(arr[curr],freq);
        }
        cout<<"W/0 taking"<<endl;
        solve(arr,ans,freq,curr+1,length);
    }

    int maxLength(vector<string>& arr) {
        vector<bool> freq(26,0);
        int ans = 0;
        solve(arr,ans,freq,0,0);
        return ans;
    }
};