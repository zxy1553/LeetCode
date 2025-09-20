#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> findAnagrams(string s, string p){
        vector<int> ans;
        if(p.length()>s.length()) return {};

        int pLen = p.length(), sLen = s.length();
        
        vector<int> pCount(26,0),sCount(26,0);

        for (auto& c: p) {
            pCount[c-'a']++;
        }

        for (int i=0; i<pLen; ++i) {
            sCount[s[i]-'a']++;
        }

        if(sCount == pCount) ans.emplace_back(0);

        for (int i=pLen; i<sLen; ++i) {
            sCount[s[i]-'a']++;
            sCount[s[i-pLen]-'a']--;
            
            if(sCount==pCount) ans.emplace_back(i-pLen+1);
        }
        return ans;
    }
};


int main(){
    string s = "cbaebabacd", p="abc";
    Solution sol;
    auto res = sol.findAnagrams(s, p);

    for (auto& num : res) {
        cout<<num<<"/n";
    }
}