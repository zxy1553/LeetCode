#include <stack>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans =0;

        heights.push_back(0);
        int n = heights.size();

        for(int i=0; i<n; ++i){
            while (!stk.empty() && heights[stk.top()]>heights[i]) {
                int heigh = heights[stk.top()];
                stk.pop();
                int width = stk.empty()?i:i-stk.top()-1;
                ans = max(ans,heigh*width);
            }
            stk.push(i);
        }
            
        return ans;
        
    }
};



int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;
    cout << sol.largestRectangleArea(heights);

}