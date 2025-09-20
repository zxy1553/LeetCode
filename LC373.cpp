#include<iostream>
#include<queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;


class Solution{

    public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<tiii,vector<tiii>, greater<tiii>> pq;
        pq.emplace(nums1[0] + nums2[0],0,0);
        while (ans.size()<k)
        {
            auto [_,i,j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j==0 && i+1<n){
                pq.emplace(nums1[i+1]+nums2[0],i+1,0);
            }
            if(j+1<m){
                pq.emplace(nums1[i]+nums2[j+1],i, j+1);
            }
        }
        return ans;

    }
};