class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> mini = {10000009, -1};
        pair<int, int> maxi = {-10000009, -1};
        pair<int, int> secondMini = {10000009, -1};
        pair<int, int> secondMaxi = {-10000009, -1};

        int n = arrays.size();
        for (int i = 0; i < n; i++) {
            if (arrays[i].back() >= maxi.first) {
                secondMaxi = maxi;
                maxi = {arrays[i].back(), i};
            } else if (arrays[i].back() >= secondMaxi.first) {
                secondMaxi = {arrays[i].back(), i};
            }
            if (arrays[i][0] <= mini.first) {
                secondMini = mini;
                mini = {arrays[i][0], i};
            } else if (arrays[i][0] <= secondMini.first) {
                secondMini = {arrays[i][0], i};
            }
        }

        cout<<"Maxi: "<<maxi.second;
        cout<<"Second Maxi: "<<secondMaxi.second;
        cout<<"Mini: "<<mini.second;
        cout<<"Second Mini: "<<secondMini.second;

        if (mini.second != maxi.second) {
            return maxi.first - mini.first;
        }
        
        return max(maxi.first - secondMini.first, secondMaxi.first - mini.first);
    }
};