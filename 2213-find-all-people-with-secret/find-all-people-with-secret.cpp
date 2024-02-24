class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map< int , set<pair<int,int> > > allMeet;
        for(auto& meet: meetings){
             int p1 = meet[0];
             int p2 = meet[1];
             int time = meet[2];
             allMeet[p1].insert({time,p2});
             allMeet[p2].insert({time,p1});
        }
        unordered_set<int> ans;
        ans.insert(0);
        ans.insert(firstPerson);
        // {Time,Person}
        queue<pair<int,int>> q;
        q.push({0,firstPerson});
        q.push({0,0});

        while(!q.empty()){
            auto qFrnt = q.front();
            q.pop();
            int fTime = qFrnt.first;
            int fPerson = qFrnt.second;

            for(auto [stTpTime, stTpPrsn]: allMeet[fPerson] ){
                if(stTpTime >= fTime){
                    ans.insert(stTpPrsn);
                    q.push({stTpTime, stTpPrsn});
                    allMeet[fPerson].erase({stTpTime, stTpPrsn});
                }
            }
        }
        vector<int> vecAns(ans.begin(), ans.end());
        return vecAns;
    }
};

// class Solution {
// public:
// vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//     unordered_map<int, set<pair<int, int>>> allMeet;
//     for(auto& meet: meetings) {
//         int p1 = meet[0];
//         int p2 = meet[1];
//         int time = meet[2];
//         allMeet[p1].insert({time, p2});
//         allMeet[p2].insert({time, p1});
//     }
//     unordered_set<int> ans;
//     ans.insert(0);
//     ans.insert(firstPerson);
    
//     queue<pair<int, int>> q;
//     q.push({0, firstPerson});
//     q.push({0, 0});

//     while(!q.empty()) {
//         auto qFrnt = q.front();
//         q.pop();
//         int fTime = qFrnt.first;
//         int fPerson = qFrnt.second;

//         set<pair<int, int>> newSet;
//         for(auto [stTpTime, stTpPrsn]: allMeet[fPerson]) {
//             if(stTpTime < fTime) {
//                 newSet.insert({stTpTime, stTpPrsn});
//             } else {
//                 ans.insert(stTpPrsn);
//                 q.push({stTpTime, stTpPrsn});
//             }
//         }
//         allMeet[fPerson] = newSet;
//     }

//     vector<int> vecAns(ans.begin(), ans.end());
//     return vecAns;
// }
// };