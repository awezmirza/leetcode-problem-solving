class Solution {
public:

    int numTeams(vector<int>& rating) {

        int n = rating.size();

        int ans = 0;
        
        for (int j = 1; j < n-1; j++) {

            int leftGreater = 0;
            int leftSmaller = 0;

            int rightGreater = 0;
            int rightSmaller = 0;

            int num = rating[j];

            for (int i = 0; i < j; i++) {
                if (rating[i] > num) {
                    leftGreater++;
                } else if (rating[i] < num) {
                    leftSmaller++;
                }
            }

            for (int k = j + 1; k < n; k++) {
                if (rating[k] > num) {
                    rightGreater++;
                } else if (rating[k] < num) {
                    rightSmaller++;
                }
            }

            ans += (leftGreater * rightSmaller);
            ans += (leftSmaller * rightGreater);
        }
        return ans;
    }
};