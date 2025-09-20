#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ret = 0, top = height[0];
        int n = height.size();
        vector<int> left(n);
        for (int i = 1; i < n; i++)
        {
            if (height[i] >= top)
            {
                top = height[i];
            }
            else
            {
                left[i] = top - height[i];
            }
        }
        int right = 0;
        top = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (height[i] >= top)
            {
                top = height[i];
                right=0;
            }
            else
            {
                right = top - height[i];
            }
            ret += min(left[i], right);
        }
        return ret;
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