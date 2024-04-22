class Solution {
public:

    char moveLeft(char ch){
        return ch == '0' ? '9' : ch - 1;
    }

    char moveRight(char ch){
        return ch == '9' ? '0' : ch + 1;
    }

    vector<string> findMoves(string pattern){
        vector<string> response;
        for(int i = 0; i < 4; i++){

            char ch = pattern[i];
            char left = moveLeft(ch);
            char right = moveRight(ch);

            pattern[i] = left;
            response.push_back(pattern);

            pattern[i] = right;
            response.push_back(pattern);

            pattern[i] = ch;
        }
        return response;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        unordered_set<string> dead(deadends.begin(), deadends.end());
        int totalNumber = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == target) return totalNumber;
                if(dead.find(curr) != dead.end()) continue;
                if(visited.find(curr) != visited.end()) continue;
                visited.insert(curr);
                vector<string> nextMoves = findMoves(curr);
                for(auto st : nextMoves){
                    q.push(st);
                }
            }
            totalNumber++;
        } 
        return -1;
    }
};