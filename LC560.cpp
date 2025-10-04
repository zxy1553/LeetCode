#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s=0;
        int ans=0;
        //记录前缀和为first的个数有second个
        unordered_map<int,int> cnt;
        for(auto num : nums){
            cnt[s]++;
            s+=num;
            if(cnt.count(s-k)){
                ans += cnt[s-k];
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums{1,1,1};

    Solution sol;

    cout << sol.subarraySum(nums,2);
}