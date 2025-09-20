#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> map;
        for(auto& num: nums){
            map[num]++;
        }

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        }; 
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);

        for(auto& [num,count]:map){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num,count); 
                }
            }else{
                q.emplace(num,count);
            }
        }
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;



    }
};