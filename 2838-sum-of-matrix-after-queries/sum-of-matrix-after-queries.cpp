class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int totalQueries = queries.size();
        int rowCt = n, colCt = n;
        unordered_set<int> seenCol;
        unordered_set<int> seenRow;
        long long ans = 0;
        for(int i = totalQueries-1;i>=0;i--){
            int type = queries[i][0];
            int idx = queries[i][1];
            int val = queries[i][2];
            if(type == 0 && (seenRow.find(idx) == seenRow.end())){
                ans+= (val*colCt);
                rowCt--;
                seenRow.insert(idx);
            }
            else if(type == 1 && (seenCol.find(idx) == seenCol.end())){
                ans+= (val*rowCt);
                colCt--;
                seenCol.insert(idx);
            }
            if(rowCt == 0 || colCt == 0) break;
        }
        return ans;
    }
};