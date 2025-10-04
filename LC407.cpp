#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1;
        int ans=0;

        for(int left=0; left<height.size(); ++left){
            
            while(left<right && height[left]>height[right]){
                ans = max(ans,height[right]*(right-left));
                right--;

            }
            ans = max(ans,height[left]*(right-left));
        }
        return ans;
    }
};


int main(){
    vector<int> height;

    int h;
    while(cin>>h){
        height.emplace_back(h);
    }

    Solution sol;

    cout << sol.maxArea(height);
    
}