#include <vector>
#include <climits>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,sum=0;
        for(auto& n: nums){
            sum = sum+n>n?sum+n:n;
            ans = max(ans,sum);
        }

        return ans;
    }
};


int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    Solution sol;

    cout << sol.maxSubArray(nums);
}