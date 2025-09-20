#include <bits/stdc++.h>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int start =0;
        int end =0;
        for(int i=0;i<s.length();++i){
            end = max(end, (int)s.rfind(s[i]));
            if(i==end){
                res.emplace_back(end-start+1);
                start = end+1;
            }

        }
        return res;
    }

};


class Solution1 {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
             mp[s[i]] = i;
        }
        vector<int> ans;
        int index = 0;
        int right = mp[s[0]];

        while (true)
        {
            for (int i = index; i <= right; i++)
            {
                if (mp[s[i]] > right) right = mp[s[i]];
            }
            ans.push_back(right - index + 1);
            if (right == s.size() - 1) break;
            index = right + 1;
            right = mp[s[index]];

        }
        return ans;
    }
};


int main(){
    string s = "ababcbacadefegdehijhklij";
    string s1 = "eccbbbbdec";
    Solution sol;
    vector<int> res = sol.partitionLabels(s1);
    for(auto i:res){
        cout<<i<<" ";
    }
}