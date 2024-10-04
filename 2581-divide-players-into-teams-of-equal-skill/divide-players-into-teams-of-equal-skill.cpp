class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill.front() + skill.back();
        int n = skill.size();
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            if (sum != (skill[i] + skill[n - 1 - i])) {
                return -1;
            }
            ans += (skill[i] * skill[n - 1 - i]);
        }
        return ans;
    }
};