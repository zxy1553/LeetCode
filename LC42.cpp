#include <iostream>
#include <vector>
using namespace std;

//当自己靠边界侧的水泥是瓶颈的时候，向中间收缩
class Solution
{
public:
    int trap(vector<int> &height){
        int res=0;
        int leftMax=0,rightMax=0;

        int left=0,right=height.size()-1;
        while(left<right){

            //更新的位置在这里是为了包括left、right自己
            leftMax=max(leftMax,height[left]);
            rightMax=max(rightMax,height[right]);

            if(leftMax<rightMax){
                res+=(leftMax-height[left]);
                left++;
            }else{
                res+=(rightMax-height[right]);
                right--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> nums2 = {4,2,0,3,2,5};
    vector<int> nums3 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(nums3) << endl;


    return 0;
}