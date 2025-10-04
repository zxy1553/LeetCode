#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for(int first=0; first<nums.size()-2; first++){
            if(first>0 && nums[first]==nums[first-1]) continue;
            if(nums[first]>0) break;

            int target = -nums[first];
            int second=first+1, third=nums.size()-1;
            while(second<third){
                

                int sum = nums[second]+nums[third];
                if(sum==target) {
                    res.emplace_back(vector{nums[first],nums[second],nums[third]});
                    while(second < third && nums[second] == nums[second+1]) {
                        second++;
                    }
                    // 去重：跳过重复的third
                    while(second < third && nums[third] == nums[third-1]) {
                        third--;
                    }
                    second++;
                    third--;
                }else if(sum<target){
                    second++;
                }else{
                    third--;
                }
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums{0,0,0,0};
    Solution sol;
    auto res = sol.threeSum(nums);
    for(auto& i: res){
        for(auto& j: i){
            cout << j<<" ";
        }
        cout <<"\n";
    }
}