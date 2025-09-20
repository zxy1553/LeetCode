#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution{
    public:
    int coinChange(vector<int>& coins, int amount){
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for(int j=0; j<coins.size(); ++j){
                if(coins[j]<=i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
        
    }
};

class Solution2{
    vector<int> count; //凑成金额i+1所需的最少硬币
    int dp(vector<int>& coins, int rem){
        if(rem < 0) return -1;  //无法凑成
        if(rem == 0) return 0;  //已经凑成，直接返回
        if(count[rem-1] != 0) return count[rem-1];
        int Min = INT_MAX;
        for(int coin:coins){
            int res = dp(coins, rem-coin);
            ///res + 1 的意思是：凑成 rem - coin 需要 res 个硬币，再加上当前这一个 coin，总共需要 res + 1 个
            if(res >= 0 && res<Min){
                Min =res+1;
            }
        }
        count[rem-1] = Min == INT_MAX? -1: Min;
        return count[rem-1];
    }

    public:
    int coinChange(vector<int>& coins, int amount){
        if(amount < 1) return 0;
        count.resize(amount);
        return dp(coins, amount);
    }

}


int main(){
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    Solution2 sol;

    cout << sol.coinChange(coins, amount);
}