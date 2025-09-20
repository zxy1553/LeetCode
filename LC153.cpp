#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low +(high-low)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};


int main(){
    // vector<int> nums = {3,4,5,1,2};
    vector<int> nums = {2};
    Solution sol = Solution();
    cout << sol.findMin(nums);
}