#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>


using namespace std;


class Solution{
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }       

        int n = prices.size();
        k = min(k, n/2);
        vector buy(n,vector<int>(k+1));
        vector sell(n,vector<int>(k+1));
        
        buy[0][0] = -prices[0];
        sell[0][0] = 0;

        for(int i=1; i<=k; ++i){
            buy[0][i] = sell[0][i] = INT_MIN /2;
        }

        for (int i = 1; i < n; ++i)
        {
            buy[i][0] = max(buy[i-1][0], sell[i-1][0]-prices[i]);
            for (int j = 1; j <= k; ++j)
            {
                buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i]);
                sell[i][j] = max(sell[i-1][j],buy[i-1][j-1]+prices[i]);
            }
        }

        return ranges::max(sell[n-1]);
        
    }

};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k = min<int>(k, prices.size() / 2) + 1;
        vector buy(k, INT_MIN), sel(k, 0);
        for (int i : prices) {
            for (int j = 1; j < k; j++) {
                buy[j] = max(buy[j], sel[j - 1] - i);
                sel[j] = max(sel[j], buy[j] + i);
            }
        }
        return sel.back();
    }
};

