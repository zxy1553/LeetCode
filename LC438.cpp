#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> findAnagrams(string s, string p){
        vector<int> res;
        if(p.length()>s.length()) return {};
        vector<int> pCnt(26,0);
        for(auto& c: p){
            pCnt[c-'a']++;
        }

        vector<int> sCnt(26,0);
        int right=0;

        for(int left=0; left<s.length()-p.length()+1; ++left){
            while(right-left<p.length()){
                sCnt[s[right++]-'a']++;
            }
            if(sCnt==pCnt){
                res.emplace_back(left);
            }
            sCnt[s[left]-'a']--;
        }
        return res;
    }
};


int main(){
    string s = "abab", p="ab";
    Solution sol;
    auto res = sol.findAnagrams(s, p);

    for (auto& num : res) {
        cout<<num<<"\n";
    }
}