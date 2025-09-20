#include<iostream>
#include<vector>
#include<unordered_map>
#include <limits>

using namespace std;

class Solution{
    public:
    int maxPoints(vector<vector<int>>& points){
        int n=points.size(), ans=0;
        for (size_t i = 0; i < n-1; ++i)
        {
            auto& p = points[i];
            unordered_map<double,int> cnt;
            for (size_t j = i+1; j < n; j++)
            {
                auto& q = points[j];
                int dx = q[0] - p[0], dy = q[1]-p[1];
                double k = dx ? 1.0 * dy / dx : numeric_limits<double>::infinity();
                ans = max(ans, ++cnt[k]);
            }
            
        }
        return ans+1;
    }
};