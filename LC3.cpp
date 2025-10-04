#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans =0;
        int left=0,right=0;
        unordered_set<char> cnt;
        
        while(right<s.length()){
            if(!cnt.count(s[right])){
                cnt.emplace(s[right]);
                right++;
            }else{
                cnt.erase(s[left]);
                left++;
            }
            ans = max(ans,right-left);
        }
        return ans;
    }
};

int main(){
    string s = "abcabcbb";
    Solution sol;
    sol.lengthOfLongestSubstring(s);
}