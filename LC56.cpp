#include <vector>
#include <algorithm>

using namespace std;

class Solution{

    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0]<b[0];
        });
        
        res.emplace_back(intervals[0]);

        for(auto& interval: intervals){
            int end = res.size()-1;
            if(interval[0] <= res[end][1]){
                res[end][1] = max(interval[1],res[end][1]);
            }else{
                res.emplace_back(interval);
            }
        }
        
        return res;
        
    }
};


int main(){
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    sol.merge(intervals);
    

}