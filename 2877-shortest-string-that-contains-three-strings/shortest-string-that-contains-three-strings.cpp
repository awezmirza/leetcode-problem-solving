class Solution {
public:

    string fit(string fst, string scnd){
        int ptr1 = 0;
        int ptr2 = 0;
        int n = fst.size();
        int m = scnd.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            int lastFound = -1;
            ptr1 = i;
            ptr2 = 0;
            if(fst[ptr1] == scnd[ptr2]){
                lastFound = ptr1;
                while(fst[ptr1] == scnd[ptr2]){
                    if(ptr1==n-1){
                        return fst.substr(0,lastFound) + scnd;
                    }
                    if(ptr2==m-1){
                        return fst;
                    }
                    ptr1++,ptr2++;
                }
            }
        }
        return fst + scnd;
    }

    string minimumString(string a, string b, string c) {
        // a -> b -> c 
        // a -> c -> b 
        // b -> a -> c 
        // b -> c -> a 
        // c -> a -> b 
        // c -> b -> a 
        string atob = fit(a,b);
       string btoc = fit(b,c);
        string atoc = fit(a,c);
         string ctob = fit(c,b);
        string ctoa = fit(c,a);
         string btoa = fit(b,a);
        
        string fst = fit(atob,c);
        
        string scnd = fit(atoc,b);
         string thrd = fit(btoa,c);
        string frth = fit(btoc,a);
        string ffth = fit(ctoa,b);
        string sxth = fit(ctob,a);
      int one = fst.length();
       
        int two = scnd.length();
        int three = thrd.length();
        int four = frth.length();
         int five = ffth.length();
        int six = sxth.length();
    
        string ans = "";

        int mini = min(one, min(two,min(three,min(four,min(five,six)))));
        if(mini == one){
            ans = fst;
        }
         if(mini == two){
            if(ans == "") ans = scnd;
            else ans = min(ans,scnd);
        }
        if(mini == three){
            if(ans == "") ans = thrd;
            else ans = min(ans,thrd);
        }
        if(mini == four){
            if(ans == "") ans = frth;
            else ans = min(ans,frth);
        }cout<<ans<<"\n";
        if(mini == five){
            if(ans == "") ans = ffth;
            else ans = min(ans,ffth);
        }cout<<ans<<"\n";
        if(mini == six){
            if(ans == "") ans = sxth;
            else ans = min(ans,sxth);
        }
        cout<<ans<<"\n";
        return ans;
    }
};