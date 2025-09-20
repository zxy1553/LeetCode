#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0, pre =0;
        
        while (i<n)
        {
            if(nums[i]!=0){
                swap(nums[i],nums[pre]);
                i++;
                pre++;
            }else{
                i++;
            }
            
        }
        
    }
};