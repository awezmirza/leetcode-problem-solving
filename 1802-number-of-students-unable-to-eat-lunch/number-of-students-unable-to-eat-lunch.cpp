class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int studPtr = 0, sandPtr = 0;
        int stSze = students.size();
        int sandSze = sandwiches.size();
        int ans = stSze;
        int lastNtFnd = -1;
        while(sandPtr < sandSze){
            if(students[studPtr] == sandwiches[sandPtr]){
                students[studPtr] = -1;
                sandwiches[sandPtr] = -1;
                ans--;
                lastNtFnd = -1;
                sandPtr++;
            }
            else{
                if(lastNtFnd == -1){
                    lastNtFnd = studPtr;
                }
                else if(studPtr == lastNtFnd){
                    break;
                }
            }
            studPtr = studPtr + 1 >= stSze ? 0 : studPtr + 1;
        }
        return ans;
    }
};