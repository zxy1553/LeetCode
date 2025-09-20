#include <cctype>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<pair<string, int>> stk;
    string curr_string = "";
    int curr_number = 0;

    for (char c : s) {
      if (isdigit(c)) {
        curr_number = curr_number * 10 + (c - '0');
      } else if (isalpha(c)) {
        curr_string+=c;
      }else if (c=='[') {
        stk.push({curr_string,curr_number});
        curr_number=0;
        curr_string="";
      }else if (c == ']') {
        auto [pre_string, num] = stk.top();
        stk.pop();
        string temp = "";
        for(int i=0; i<num;++i){
            temp+=curr_string;
        }
        curr_string = pre_string + temp;
      }
    }
    return curr_string;
  }
};
