// class Solution {
// public:
//     vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
//         int qs = queries.size();
//         vector<int> nums(n, 0);
//         vector<int> answer(qs, 0);
//         int ans = 0;
//         for (int i = 0; i < qs; i++) {
//             int index = queries[i][0];
//             int color = queries[i][1];
//             int adj = 0;

//             int left = index - 1 > 0 ? nums[index - 1] : 0;
//             int right = nums[index + 1];

//             if (nums[index] != 0 && nums[index] == right) ans--;
//             if (nums[index] != 0 && nums[index] == left) ans--;

//             nums[index] = color;

//             if (left == nums[index]) ans++;
//             if (right == nums[index]) ans++;
            
//             answer[i] = ans;
//         }
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector <int> colors(n);
        vector<int> ans;
        int count=0;
        //int num_queries=queries.size();
        for(int i=0;i<queries.size();i++){
            int temp = queries[i][0]; // the index element going to be changed
            if(temp!=0 && colors[temp]==colors[temp-1] &&colors[temp]!=0){
                    count--;
                }
             if(temp!=n-1 && colors[temp]==colors[temp+1] && colors[temp]!=0){
                count--;
            }
            colors[queries[i][0]]=queries[i][1];
            
             if(temp!=0 && colors[temp]==colors[temp-1]&&colors[temp]!=0 ){
                   count++;
                }
             if(temp!=n-1 && colors[temp]==colors[temp+1]&&colors[temp]!=0 ){
                count++;
            }

            //for(int j=0;j<n-1;j++){
                
            //}
            ans.push_back(count);
        }
        return ans;
    }
};