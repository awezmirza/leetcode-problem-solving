class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n = version1.size();
        int m = version2.size();

        int v1Ptr = 0;
        int v2Ptr = 0;


        while(v1Ptr < n || v2Ptr < m){

            string currRev1 = "0";
            string currRev2 = "0";

            while(v1Ptr < n && version1[v1Ptr] != '.'){
                currRev1.push_back(version1[v1Ptr]);
                v1Ptr++;
            }
            while(v2Ptr < m && version2[v2Ptr] != '.'){
                currRev2.push_back(version2[v2Ptr]);
                v2Ptr++;
            }

            cout<<currRev1<<" "<<currRev2<<endl;

            int v1 = stoi(currRev1);
            int v2 = stoi(currRev2);
            if(v1 < v2){
                return -1;
            }
            else if(v1 > v2){
                return 1;
            }
            v1Ptr++;
            v2Ptr++;
        }
        return 0;
    }
};