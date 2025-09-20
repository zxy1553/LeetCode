#include <iostream>
#include <vector>

using namespace std;


void dfs(const int& n, const int& m, const vector<int>& prices, int& ans, vector<int> res, int index){
    if(res.size()==2){
        int sum = res[0] + res[1];
        if(sum%m == 0){
            ans++;
        }
        return;
    }

    for(int i=index; i<n; ++i){
        res.emplace_back(prices[i]);
        dfs(n,m,prices,ans,res,i+1);
        res.pop_back();
    }
}

int main(){
    int n,m;
    cin >>n >> m;
    vector<int> prices(n,0);
    for(int i=0; i<n; ++i){
        cin>>prices[i];
    }
    int ans=0;
    vector<vector<int>> results;
    vector<int> res;
    dfs(n,m,prices, ans, res,0);
    cout << ans;
}