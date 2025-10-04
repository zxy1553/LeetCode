#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
   
// 本题最精彩的地方在于用valid来记录当前覆盖的字母个数。
// 需要将window结合valid来判断当前窗口是否覆盖
// 不需要存结果，只需要start和len
public:
    string minWindow(string s, string t) {
        int start=0 ,len=INT_MAX;
        if(s.length()<t.length()) return "";
        unordered_map<char,int> need, window;
        for(auto& c:t) need[c]++;
        int valid = 0;

        int left=0;
        for(int right=0; right<s.size(); ++right){
            char c = s[right];

            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }

            while(valid == need.size()){
                if(right-left+1<len){
                    start = left;
                    len = right-left+1;
                }
                
                char d = s[left++];

                if(need.count(d)){
                    if(window[d]==need[d]) valid--;
                    window[d]--;
                }
            }
        }

        if(len == INT_MAX) return "";
        return s.substr(start,len);
    }
};


int main(){
    string s = "adobecodebanc";
    string t = "abc";

    Solution sol;
    sol.minWindow(s,t);
}