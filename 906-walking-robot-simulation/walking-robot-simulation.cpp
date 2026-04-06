class Solution {
public:

    pair<int, int> newDir(int movX, int movY, int command) {
        if (command == -1) {
            if (movX == 0 && movY == 1) {
                movX = 1, movY = 0;
            } else if (movX == 1 && movY == 0) {
                movX = 0, movY = -1;
            } else if (movX == 0 && movY == -1) {
                movX = -1, movY = 0;
            } else {
                movX = 0, movY = 1;
            }
        } else {
            if (movX == 0 && movY == 1) {
                movX = -1, movY = 0;
            } else if (movX == 1 && movY == 0) {
                movX = 0, movY = 1;
            } else if (movX == 0 && movY == -1) {
                movX = 1, movY = 0;
            } else {
                movX = 0, movY = -1;
            }
        }

        return {movX, movY};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> mpHor, mpVer;

        for (auto obstacle : obstacles) {
            mpHor[obstacle[0]].insert(obstacle[1]);
            mpVer[obstacle[1]].insert(obstacle[0]);
        }

        int currX = 0, currY = 0;
        int movX = 0;
        int movY = 1;

        int ans = 0;

        for (int command : commands) {
            if (command == -1 || command == -2) {
                auto nDir = newDir(movX, movY, command);
                movX = nDir.first;
                movY = nDir.second; 
            } else {
                if (movX == 0) {
                    int st = currY;
                    int end = currY + (movY) * command;
                    if (movY == 1) {
                        for (int i = 1; i <= command; i++) {
                            if (mpVer[currY + 1].count(currX)) {
                                break;
                            }
                            currY++;
                        }
                    } else {
                        for (int i = 1; i <= command; i++) {
                            if (mpVer[currY - 1].count(currX)) {
                                break;
                            }
                            currY--;
                        }
                    }
                } else {
                    int st = currX;
                    int end = currX + (movX) * command;
                    if (movX == 1) {
                        for (int i = 1; i <= command; i++) {
                            if (mpHor[currX + 1].count(currY)) {
                                break;
                            }
                            currX++;
                        }
                    } else {
                        for (int i = 1; i <= command; i++) {
                            if (mpHor[currX - 1].count(currY)) {
                                break;
                            }
                            currX--;
                        }
                    }
                }
            }

            ans = max(ans, abs(currX) * abs(currX) + abs(currY) * abs(currY));
        }

        return ans;
    }
};