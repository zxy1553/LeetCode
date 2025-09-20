#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:
    int rob(vector<int>& nums){
        int n = nums.size();
        int dp[n];
        dp[0]=nums[0], dp[1]=max(nums[0],nums[1]);
        for (size_t i = 2; i < n; ++i)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
        


    }
};

int main(){

    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums);
}