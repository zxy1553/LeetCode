#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        vector f(m+1,vector<int>(n+1));
        int ans = 0;
        for(int i=0; i<m; i++){
            if(matrix[i][j] == '1'){
                f[i+1][j+1] = min({f[i][j], f[i][j+1], f[i+1][j]})+1;
                ans = max(ans, f[i+1][j+1]);
            }
        }
        return ans* ans;
    }
};