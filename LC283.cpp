#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]){
                swap(nums[i],nums[len++]);
            }
        }
    }
};



int main()
{
    vector<int> nums{0,1,0,3,12};
    Solution sol;

    sol.moveZeroes(nums);

    for(auto n : nums){
        cout << n <<" ";

    }
}