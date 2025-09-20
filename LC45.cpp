#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int maxPos=0, n=nums.size(), end=0, step=0;
            for(int i=0;i<nums.size();i++){
                if(maxPos>=i){
                    maxPos=max(maxPos,i+nums[i]);
                    if(i==end){
                        end=maxPos;
                        ++step;
                    }
                }
            }
    
            return step;
        }
    };

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,2,3};
    cout << sol.jump(nums1) << endl;


    return 0;
}
