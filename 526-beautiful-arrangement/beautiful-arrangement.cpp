class Solution {
public:

    void generateAllPerms(int& ans, vector<int>& onePossiblePerm, int ptr) {
        int n = onePossiblePerm.size();
        if (ptr >= n) {
            for (int num : onePossiblePerm) {
                cout<<num<<" ";
            }
            cout<<endl;
            ans++;
            return;
        }

        for (int i = ptr; i < n; i++) {
            swap(onePossiblePerm[ptr], onePossiblePerm[i]); 
            if (onePossiblePerm[ptr] % (ptr + 1) == 0 || (ptr + 1) % onePossiblePerm[ptr] == 0) {
                generateAllPerms(ans, onePossiblePerm, ptr + 1);
            }            
            swap(onePossiblePerm[ptr], onePossiblePerm[i]);
        }
    }

    int countArrangement(int n) {
        vector<int> onePossiblePerm;
        for (int i = 1; i <= n; i++) {
            onePossiblePerm.push_back(i);
        }

        int ans = 0;

        generateAllPerms(ans, onePossiblePerm, 0);

        return ans;
    }
};