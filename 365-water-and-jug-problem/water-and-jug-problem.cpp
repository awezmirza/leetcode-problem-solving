class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) {
            return false;
        }
        set<pair<int, int>> checked;
        queue<pair<int, int>> q;
        q.push({0, 0}); 
        checked.insert({0, 0});

        while (!q.empty()) {
            auto fr = q.front();
            if (fr.first + fr.second == target) {
                return true;
            }
            q.pop();
            // X ko pura bhar lege
            if (checked.find({x, fr.second}) == checked.end()) {
                checked.insert({x, fr.second});
                q.push({x, fr.second}); 
            }

            // Y ko pura bhar lege
            if (checked.find({fr.first, y}) == checked.end()) {
                checked.insert({fr.first, y});
                q.push({fr.first, y}); 
            }

            // X ko pura khaali kr lege
            if (checked.find({0, fr.second}) == checked.end()) {
                checked.insert({0, fr.second});
                q.push({0, fr.second}); 
            }

            // Y ko pura khaali kr lege
            if (checked.find({fr.first, 0}) == checked.end()) {
                checked.insert({fr.first, 0});
                q.push({fr.first, 0}); 
            }

            // X ko Y me daal dege
            if (checked.find({max(0, fr.first - (y - fr.second)), min(y, fr.first + fr.second)}) == checked.end()) {
                checked.insert({max(0, fr.first - (y - fr.second)), min(y, fr.first + fr.second)});
                q.push({max(0, fr.first - (y - fr.second)), min(y, fr.first + fr.second)}); 
            }

            // Y ko X me daal dege
            if (checked.find({min(x, fr.first + fr.second), max(0, fr.second - (x - fr.first))}) == checked.end()) {
                checked.insert({min(x, fr.first + fr.second), max(0, fr.second - (x - fr.first))});
                q.push({x, max(min(x, fr.first + fr.second), fr.second - (x - fr.first))}); 
            }
        }
        return false;
    }
};