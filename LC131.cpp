#include <vector>
#include <string>

using namespace std;


class Solution {
    private:
    bool isPalindrome(const string& s, int left, int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }

        }

        return true;
    }


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        int n = s.length();
        
        auto dfs = [&](this auto&& dfs, int idx, int start){
            if(idx==n){
                ans.emplace_back(path);
                return;
            }

            if(idx<n-1){
                dfs(idx+1,start);
            }


            if(isPalindrome(s, start, idx)){
                path.emplace_back(s.substr(start,idx-start+1));

                dfs(idx+1,idx+1);
                path.pop_back();
            }
        };

        dfs(0,0);
        return ans;


    }
};