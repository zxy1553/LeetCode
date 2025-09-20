#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;

        vector<int> rightMaxProfit(n,0), leftMaxProfit(n,0);
        int minPrice = prices[0], maxPrice = prices[n-1];  //最大价格用于卖出，最小价格用于买入。

        for(int i=1; i<n; ++i){
            minPrice = min(minPrice,prices[i]);
            int currentProfit = prices[i]-minPrice;
            leftMaxProfit[i] = max(leftMaxProfit[i-1],currentProfit);
        }

        for(int i=n-2; i>-1; --i){
            maxPrice = max(maxPrice,prices[i]);
            int currentProfit = maxPrice - prices[i];
            rightMaxProfit[i] = max(rightMaxProfit[i+1],currentProfit);
        }

        int maxTotalProfit = 0;
        for(int i=0; i<n; ++i){
            maxTotalProfit = max(maxTotalProfit, leftMaxProfit[i] + rightMaxProfit[i]);
        }
            
        return maxTotalProfit;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1,buy1+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
        
    }
};
