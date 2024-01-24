class Solution {
public:
    string fit(string fst, string scnd) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n = fst.size();
        int m = scnd.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            int lastFound = -1;
            ptr1 = i;
            ptr2 = 0;
            if (fst[ptr1] == scnd[ptr2]) {
                lastFound = ptr1;
                while (fst[ptr1] == scnd[ptr2]) {
                    if (ptr1 == n - 1) {
                        return fst.substr(0, lastFound) + scnd;
                    }
                    if (ptr2 == m - 1) {
                        return fst;
                    }
                    ptr1++, ptr2++;
                }
            }
        }
        return fst + scnd;
    }

    string minimum(string a,string b){
        if(a.size() == b.size()){
            return min(a,b);
        }
        else if(a.size() < b.size()){
            return a;
        }
        else{
            return b;
        }
    }

    string minimumString(string a, string b, string c) {
        // a -> b -> c
        // a -> c -> b
        // b -> a -> c
        // b -> c -> a
        // c -> a -> b
        // c -> b -> a

        string fst = fit(fit(a, b), c);
        string scnd = fit(fit(a, c), b);
        string thrd = fit(fit(b, a), c);
        string frth = fit(fit(b, c), a);
        string ffth = fit(fit(c, a), b);
        string sxth = fit(fit(c, b), a);

        string mini = minimum(fst,minimum(scnd,minimum(thrd,minimum(frth,minimum(ffth,sxth)))));
        // string mini = minimum(fst,scnd);
        // string mini = minimum(fst,scnd);
        // string mini = minimum(fst,scnd);
        // string mini = minimum(fst,scnd);

        return mini;

        // int one = fst.length();
        // int two = scnd.length();
        // int three = thrd.length();
        // int four = frth.length();
        // int five = ffth.length();
        // int six = sxth.length();

        // string ans = "";

        // int mini = min(one, min(two, min(three, min(four, min(five, six)))));
        // if (mini == one) {
        //     ans = fst;
        // }
        // if (mini == two) {
        //     if (ans == "")
        //         ans = scnd;
        //     else
        //         ans = min(ans, scnd);
        // }
        // if (mini == three) {
        //     if (ans == "")
        //         ans = thrd;
        //     else
        //         ans = min(ans, thrd);
        // }
        // if (mini == four) {
        //     if (ans == "")
        //         ans = frth;
        //     else
        //         ans = min(ans, frth);
        // }
        // if (mini == five) {
        //     if (ans == "")
        //         ans = ffth;
        //     else
        //         ans = min(ans, ffth);
        // }
        // if (mini == six) {
        //     if (ans == "")
        //         ans = sxth;
        //     else
        //         ans = min(ans, sxth);
        // }
        // return ans;
    }
};