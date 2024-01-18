class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int qs = queries.size();
        vector<int> nums(n, 0);
        vector<int> answer;
        int ans = 0;

        for (int i = 0; i < qs; i++) {
            int index = queries[i][0];
            int color = queries[i][1];

            int left = index - 1 < 0 ? 0 : nums[index - 1];
            int right = index + 1 == n ? 0 : nums[index + 1];

            if (nums[index] != 0 && nums[index] == left)
                ans--;
            if (nums[index] != 0 && nums[index] == right)
                ans--;

            nums[index] = color;

            if (left == nums[index])
                ans++;
            if (right == nums[index])
                ans++;

            answer.push_back(ans);
        }
        return answer;
    }
};