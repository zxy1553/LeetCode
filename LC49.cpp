#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>,int> hash;

        for(auto& str : strs){
            vector<int> cnt(26,0);
            for(auto& c: str){
                cnt[c-'0']++;
            }
            if(auto& it = hash.find(cnt) != hash.end()){
                
            }
        }
    }
};