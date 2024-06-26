class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int st = 0;
        int end = people.size() - 1;
        int boats = 0;
        while(st <= end){
            if(people[st] + people[end] <= limit){
                st++;
                end--;
            }
            else{
                end--;
            }
            boats++;
        }
        return boats;
    }
};