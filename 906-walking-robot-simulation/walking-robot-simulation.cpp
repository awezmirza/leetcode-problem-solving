class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // N => 0
        // E => 1
        // S => 2
        // W => 3

        int ans = 0;
        int currX = 0, currY = 0;
        int dirn = 0;

        unordered_set<string> st;
        for (auto obstacle : obstacles) {
            string key = to_string(obstacle[0]) + "_" + to_string(obstacle[1]);
            cout<<key<<" ";
            st.insert(key);
        }
        cout<<endl;

        for (int command : commands) {
            if (command == -1) {
                dirn = (dirn + 1) % 4;
            } else if (command == -2) {
                if (dirn == 0) {
                    dirn = 3;
                } else 
                    dirn = (dirn - 1) % 4;
            } else {
                for (int step = 0; step < command; step++) {
                    
                    int newY = currY;
                    int newX = currX;

                    if (dirn == 0) {
                        newY += 1;
                    } else if (dirn == 1) {
                        newX += 1;
                    } else if (dirn == 2) {
                        newY -= 1;
                    } else {
                        newX -= 1;
                    }

                    string key = to_string(newX) + "_" + to_string(newY);
                    cout<<key<<" ";
                    if (st.find(key) != st.end()) {
                        break;
                    }

                    currX = newX;
                    currY = newY;
                }
            }
            ans = max(ans, (currX * currX + currY * currY));
        }
        return ans;
    }
};