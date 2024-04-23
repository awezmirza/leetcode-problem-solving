class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<int> deg(n);
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

            deg[edge[0]]++;
            deg[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(deg[i] == 1){
                q.push(i);
            }
        }

        while(n > 2){
            int qsz = q.size();
            n -= qsz;
            for(int i = 0; i < qsz; i++){

                int fr = q.front();
                q.pop();
                deg[fr]--;

                for(auto el : graph[fr]){
                    deg[el]--;
                    if(deg[el] == 1){
                        q.push(el);
                    }
                }

            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};