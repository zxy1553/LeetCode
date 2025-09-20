

#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int, int>> stk;
        stk.push({temperatures[0],0});

        for(int i=1; i<n; ++i){
            int curr_temp = temperatures[i];
            while (!stk.empty()) {
                auto [top_temp,top_day] = stk.top();
                if(top_temp < curr_temp){
                    ans[top_day] = i-top_day;
                    stk.pop();
                }else{break;}
            }
            stk.push({curr_temp,i});

        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // 初始化结果数组
        stack<int> stk; // 栈仅存储索引

        for (int i = 0; i < n; ++i) {
            // 当前温度高于栈顶温度时，计算天数差
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int top_day = stk.top();
                ans[top_day] = i - top_day; // 计算天数差
                stk.pop(); // 弹出栈顶
            }
            stk.push(i); // 当前天数入栈
        }
        return ans;
    }
};

int main(){
    vector<int> temperatures={73,74,75,71,69,72,76,73};
    Solution sol;
    for(auto& t: sol.dailyTemperatures(temperatures) ){
        cout << t << "\n";
    }
}