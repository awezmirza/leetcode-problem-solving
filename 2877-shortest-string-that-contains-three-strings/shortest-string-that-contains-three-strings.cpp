class Solution {
public:
    string fit(string fst, string scnd) {
        int ptr1 = 0, ptr2 = 0;
        int n = fst.size(), m = scnd.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            int lastFound = -1;
            ptr1 = i, ptr2 = 0;
            if (fst[ptr1] == scnd[ptr2]) {
                lastFound = ptr1;
                while (fst[ptr1] == scnd[ptr2]) {
                    if (ptr1 == n - 1) return fst.substr(0, lastFound) + scnd;
                    if (ptr2 == m - 1) return fst;
                    ptr1++, ptr2++;
                }
            }
        }
        return fst + scnd;
    }

    string minimum(string a,string b){
        // If Both are of same size, returning lexicographically smaller string
        if(a.size() == b.size()) return min(a,b);
        else if(a.size() < b.size()) return a; 
        else return b;
    }
    string minimumString(string a, string b, string c) {
        // There are only 6 Possibilities
        // a -> b -> c
        // a -> c -> b
        // b -> a -> c
        // b -> c -> a
        // c -> a -> b
        // c -> b -> a

        // Finding All Possible Strings
        string fst = fit(fit(a, b), c);
        string scnd = fit(fit(a, c), b);
        string thrd = fit(fit(b, a), c);
        string frth = fit(fit(b, c), a);
        string ffth = fit(fit(c, a), b);
        string sxth = fit(fit(c, b), a);

        // Finding Minimum of this 6  Strings
        string mini = minimum(fst,minimum(scnd,minimum(thrd,minimum(frth,minimum(ffth,sxth)))));

        return mini;
    }
};