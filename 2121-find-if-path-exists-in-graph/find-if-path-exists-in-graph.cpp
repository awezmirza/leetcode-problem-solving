class Solution {
public:

    bool dfs(unordered_map<int,vector<int>>& mp, int source, int destination, vector<bool>& visited){
        if(mp.find(source) == mp.end()){
            return 0;
        }
        
        for(auto el : mp[source]){
            if(el == destination){
                return true;
            }
            if(!visited[el]){
                visited[el] = true;
                bool ans = dfs(mp, el, destination, visited);
                if(ans) return ans;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,0);
        for(auto edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        
        bool ans = dfs(mp, source, destination, visited);
        return ans;
    }
};