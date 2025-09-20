#include<iostream>
#include<vector>

using namespace std;


class NumMatrix {
    private:
    vector<vector<int>> sum;
    public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        sum.assign(m+1,vector<int>(n+1,0));

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                sum[i+1][j+1] = matrix[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];                
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans = sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];


        return ans;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


int main(){
    vector<vector<int>> matrix = {{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}}};
    NumMatrix* obj = new NumMatrix(matrix);
    // int param_1 = obj->sumRegion(1,1,2,2);
    int param_2 = obj->sumRegion(0,0,0,0);
    // int param_3 = obj->sumRegion(1,2,2,4);
    cout << param_2;
    
}