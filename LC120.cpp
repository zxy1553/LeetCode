#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=0;

        vector<vector<int>> dp(triangle.begin(),triangle.end());
        for(int i=1; i<triangle.size(); ++i){
            for(int j=0; j<triangle[i].size(); ++j){
                if(j==0){
                    dp[i][j] += dp[i-1][j];
                }else if(j==triangle[i].size()-1){
                    dp[i][j] += dp[i-1][j-1];
                }else{
                    dp[i][j] += min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        int n = triangle.size();
        ans = ranges::min(dp[n-1]);

        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> tri = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << sol.minimumTotal(tri);
}