class DSU {
    vector<int> par;
    public:

    DSU() {
        par.resize(26);
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }
    }

    int find(int alp) {
        if (par[alp] == alp) {
            return alp;
        }

        return par[alp] = find(par[alp]);
    }

    void add(int num1, int num2) {
        if (num1 == num2) {
            return;
        }

        int par1 = find(num1);
        int par2 = find(num2);
        if (par1 > par2) {
            par[par1] = par2;
        } else {
            par[par2] = par1;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DSU un;
        for (int i = 0; i < n; i++) {
            un.add(s1[i] - 'a', s2[i] - 'a');
        }

        string ans;

        for (char s : baseStr) {
            ans.push_back('a' + un.find(s - 'a'));
        }

        return ans;
    }
};