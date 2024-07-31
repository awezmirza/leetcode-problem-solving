class Solution {
public:

    int solve(vector<vector<int>>& books, int shelfWidth, int index, int widthTillNow, int maxHtInCurrShelf, vector<vector<int>>& dp) {
        if (index >= books.size()) {
            return 0;
        }

        if (dp[index][widthTillNow] != -1) {
            return dp[index][widthTillNow];
        }

        // Iss shelf me daalege
        int take = 10000000;
        if (widthTillNow + books[index][0] <= shelfWidth) {
            int increaseInHt = 0;
            if (maxHtInCurrShelf < books[index][1]) {
                increaseInHt = books[index][1] - maxHtInCurrShelf;
            } 
            take = increaseInHt + solve(books, shelfWidth, index + 1, widthTillNow + books[index][0], max(maxHtInCurrShelf, books[index][1]), dp);
        }

        // Dusre shelf me daalege
        int leave = books[index][1] + solve(books, shelfWidth, index + 1, books[index][0], books[index][1], dp);

        return dp[index][widthTillNow] = min(take, leave);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));
        int ans = solve(books, shelfWidth, 0, 0, 0, dp);
        return ans;
    }
};