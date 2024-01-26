class Solution {
public:
    string fit(string a, string b) {
        int aSze = a.size(), bSze = b.size();
        for (int i = 0; i < aSze; i++) {
            int ptr1 = i;
            int ptr2 = 0;
            while (a[ptr1] == b[ptr2]) {
                if (ptr1 == aSze - 1) {
                    return a + b.substr(ptr2 + 1,bSze-ptr2);
                }
                if (ptr2 == bSze - 1) {
                    return a;
                }
                ptr1++,ptr2++;
            }
        }
        return a + b;
    }

    string minim(string a, string b) {
        if (a.size() < b.size()) {
            return a;
        } else if (a.size() > b.size()) {
            return b;
        } else {
            return min(a, b);
        }
    }

    string minimumString(string a, string b, string c) {
        // a->b->c
        // a->c->b
        // b->a->c
        // b->c->a
        // c->b->a
        // c->a->b
        string ab = fit(a, b);
        string bc = fit(b, c);
        string ac = fit(a, c);
        string cb = fit(c, b);
        string ba = fit(b, a);
        string ca = fit(c, a);

        string abc = fit(ab, c);
        string acb = fit(ac, b);
        string bac = fit(ba, c);
        string bca = fit(bc, a);
        string cba = fit(cb, a);
        string cab = fit(ca, b);

        string mini =
            minim(abc, minim(acb, minim(bac, minim(bca, minim(cba, cab)))));
        return mini;
    }
};