class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSze = s.size();
        int tSze = t.size();
        if(sSze != tSze) return false;
        vector<int> sVector(26,0);
        vector<int> tVector(26,0);

        for(int i=0;i<sSze;i++){
            sVector[ s[i] - 'a' ]++;
            tVector[ t[i] - 'a' ]++;
        }
        return sVector==tVector;
    }
};