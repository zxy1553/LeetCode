#include <vector>
#include <queue>

using namespace std;


class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        priority_queue<pair<int,int>> q;

        int left=0,right=k;
        
        for(int i=0;i <k; ++i){
            q.emplace(nums[i],i);
        }
        
        vector<int> res = {q.top().first};

        for(int i=k; i<n; ++i){
            q.emplace(nums[i],i);
            while(q.top().second <= i-k){
                q.pop();
            }
            res.emplace_back(q.top().first);

        }
        return res;
        

    }
};
