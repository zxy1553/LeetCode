#include <cstdint>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector board(n,string(n,'.'));
        vector<uint8_t> col(n), diag1(n*2-1), diag2(n*2-1);

        auto dfs = [&](this auto&& dfs, int r){
            if(r==n){
                ans.emplace_back(board);
                return;
            }
            
            for (int c=0; c<n; ++c) {
                int rc = r-c+n-1;
                if(!col[c] && !diag1[c+r] && !diag2[rc]){
                    board[r][c] ='Q';
                    col[c]=diag1[r+c]=diag2[rc]=true;
                    dfs(r+1);
                    col[c] = diag1[r+c] = diag2[rc] =false;
                    board[r][c]='.';
                }
            
            }


        };
        dfs(0);
        return ans;
    }
};