#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(auto& str: strs){
            string sorted_str = str;
            ranges::sort(sorted_str);
            hash[sorted_str].emplace_back(str);
        }
        
        vector<vector<string>> res(hash.size());

        int index=0;
        for(auto& [_,val]: hash){
            res[index++] = val;
        }
        return res;
    }
};
int main(){
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;

    auto res = sol.groupAnagrams(strs);
    
    for(auto strs: res){
        for(auto str: strs){
            cout << str <<" ";
        }
        cout << "\n";
    }
}