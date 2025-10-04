#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(),nums.end());
        int ans = 0;

        for(auto& num: hs){
            if(hs.count(num-1)){
                continue;
            }else{
                int len = 1;
                while(hs.count(num + len)){
                    len++;
                }
                ans = max(ans,len);
            }


        }
        return ans;
    }
};



int main(){
    vector nums{0,3,7,2,5,8,4,6,0,1};
    Solution sol;
    cout << sol.longestConsecutive(nums);
}