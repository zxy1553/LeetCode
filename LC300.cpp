#include<iostream>
#include<vector>



using namespace std;



class Solution{
    public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        int ans = 1;
        vector<int> dp(n,1);
        for(int i=1; i< n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

class Solution2{
    public:
    int lengthOfLIS(vector<int>& nums){
        int len = 1, n = (int)nums.size();
        if(n==0){
            return 0;
        }
        vector<int> d(n+1,0);
        d[len] = nums[0];
        for(int i=1; i<n; ++i){
            if(nums[i] > d[len]){
                d[++len] = nums[i];
            }else{
                int l=1, r=len, pos=0;
                while(l<=r){
                    int mid = (l+r)>>1;
                    if(d[mid]<nums[i]){
                        pos = mid;
                        l=mid+1;
                    }else{
                        r = mid-1;
                    }
                    d[pos+1] = nums[i];
                }
            }
        }
        return len;
    }
}



int main(){
    Solution sol;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout<<sol.lengthOfLIS(nums);
}