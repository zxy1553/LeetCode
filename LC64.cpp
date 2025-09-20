#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    int minPathSum(vector<vector<int>>& grid){
        if(grid.size()==0 || grid[0].size() == 0){
            return 0;
        }
        int rows = grid.size(), cols = grid[0].size();
        auto dp =vector<vector<int>> (rows, vector<int>(cols));
        dp[0][0]=grid[0][0];
        for(int i=1; i<rows; ++i){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<cols; ++i){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }

        for(int i=1; i<rows; ++i){
            for (int j = 1; j < cols; ++j)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];

    }



};

class Solution2{
private:
    vector<vector<int>> memo;
    int m,n;

public:
    int minPathSum(vector<vector<int>>& grid){
        m = grid.size();
        if(m==0) return 0;
        n = grid[0].size();
        if(n==0) return 0; 

        memo.assign(m,vector<int>(n, -1));
        return minPath(grid,0,0);
    }

private:
    int minPath(vector<vector<int>>& grid, int i, int j){
        if(i>=m || j >= n){
            return 1e9;
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int downPath = minPath(grid, i+1,j);
        int rightPath = minPath(grid, i,j+1);

        return memo[i][j] = grid[i][j] +min(downPath,rightPath);
    }


};

int main(){

}