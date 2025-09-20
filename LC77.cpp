#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> results;
        vector<int> res;

        dfs(n, k, res, results, 1);
        return results;
    }

    void dfs(const int& n, const int& k, vector<int>& res, vector<vector<int>>& results, int index){
        if(res.size() == k){
            results.emplace_back(res);
            return;
        }

        for(int i=index; i<n+1; ++i){
            res.emplace_back(i);
            dfs(n, k, res, results, i+1);
            res.pop_back();
        }

        
    }

};

void printResults(const vector<vector<int>>& results, const string& title) {
    cout << title << endl;
    cout << "结果数量: " << results.size() << endl;
    cout << "具体组合: [";
    
    for(size_t i = 0; i < results.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < results[i].size(); ++j) {
            cout << results[i][j];
            if(j < results[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i < results.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main(){
    cout << "=== 组合问题 (LeetCode 77) 测试 ===" << endl;
    
    Solution solution;
    
    // 测试用例1: C(4,2) = 6种组合
    cout << "\n测试用例1: n=4, k=2" << endl;
    cout << "期望结果: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]" << endl;
    
    auto result1 = solution.combine(4, 2);
    printResults(result1, "结果:");
    
    
//    // 测试用例2: C(3,3) = 1种组合
//    cout << "\n测试用例2: n=3, k=3" << endl;
//    cout << "期望结果: [[1,2,3]]" << endl;
//    
//    auto result2 = solution.combine(3, 3);
//    printResults(result2, "修正版本结果:");
//    
//    // 测试用例3: C(5,3) = 10种组合
//    cout << "\n测试用例3: n=5, k=3" << endl;
//    cout << "期望结果: 10种组合" << endl;
//    
//    auto result3 = solution.combine(5, 3);
//    printResults(result3, "修正版本结果:");
//    
//    // 测试用例4: C(1,1) = 1种组合
//    cout << "\n测试用例4: n=1, k=1" << endl;
//    cout << "期望结果: [[1]]" << endl;
//    
//    auto result4 = solution.combine(1, 1);
//    printResults(result4, "修正版本结果:");
//    
//    // 边界测试: C(4,1) = 4种组合
//    cout << "\n测试用例5: n=4, k=1" << endl;
//    cout << "期望结果: [[1],[2],[3],[4]]" << endl;
//    
//    auto result5 = solution.combine(4, 1);
//    printResults(result5, "修正版本结果:");
//    
//    // 数学验证
//    cout << "\n=== 数学验证 ===" << endl;
//    
//    // 计算组合数的函数
//    auto factorial = [](int n) -> long long {
//        long long result = 1;
//        for(int i = 2; i <= n; ++i) {
//            result *= i;
//        }
//        return result;
//    };
//    
//    auto combination = [&](int n, int k) -> long long {
//        if(k > n || k < 0) return 0;
//        if(k == 0 || k == n) return 1;
//        return factorial(n) / (factorial(k) * factorial(n - k));
//    };
//    
//    // 验证各个测试用例
//    vector<pair<int,int>> testCases = {{4,2}, {3,3}, {5,3}, {1,1}, {4,1}};
//    
//    for(auto& tc : testCases) {
//        int n = tc.first, k = tc.second;
//        auto result = solution.combine(n, k);
//        long long expected = combination(n, k);
//        
//        cout << "C(" << n << "," << k << ") = " << expected 
//             << ", 实际得到: " << result.size() 
//             << (result.size() == expected ? " ✅" : " ❌") << endl;
//    }
}