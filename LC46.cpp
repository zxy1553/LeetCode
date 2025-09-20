
#include <bits/stdc++.h>

using namespace std;

// class Solution{
// public:
//     vector<vector<int>> permute(vector<int>& nums){
//         vector<vector<int>> results;
//         sort(nums.begin(), nums.end());
//         do{
//             results.emplace_back(nums); 
//         }
//         while(next_permutation(nums.begin(),nums.end()));
//         
//         return results;
//     }
// };


class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<bool> visited(nums.size(),false);

        dfs(nums, results, res, visited);
        return results;
    }


    void dfs(const vector<int>& nums, vector<vector<int>>& results, vector<int>& res, vector<bool>& visited){
        if(res.size()==nums.size()){
            results.emplace_back(res);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if(!visited[i]){
                res.emplace_back(nums[i]);
                visited[i]=true;
                dfs(nums, results, res, visited);
                res.pop_back();
                visited[i]=false;
            }

        }
        
    }
};
void printResults(const vector<vector<int>>& results) {
    cout << "结果数量: " << results.size() << endl;
    cout << "具体组合: [";
    
    for(size_t i = 0; i < results.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < results[i].size(); ++j) {
            cout << results[i][j];
            if(j < results[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i < results.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main(){
    vector<int> nums = {1,2,3};
    Solution solution;
    auto results = solution.permute(nums);
    printResults(results);
}