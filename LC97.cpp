#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    bool isInterleave(string s1, string s2, string s3){
        auto f = vector<vector<int>> (s1.size()+1, vector<int>(s2.size()+1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if(n+m != t){
            return false;
        }

        f[0][0] = true;
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=m; ++j){
                int p = j+i-1;
                if(i>0){
                    f[i][j] |= (f[i-1][j] && s1[i-1]==s3[p]);
                }
                if(j>0){
                    f[i][j] |= (f[i][j-1] && s2[j-1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};


class Solution2{
public:
    bool isInterleave(string s1, string s2, string s3){
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size()){
            return false;
        }

        vector memo(n+1, vector<int>(m+1,-1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> bool{
            if(i<0 && j<0){
                return true;
            }
            int& res = memo[i+1][j+1];
            if(res != -1){
                return res;
            }
            return res = i >= 0 && s1[i] == s3[i+j+1] && dfs(i-1,j) || j>=0 && s2[j] == s3[i+j+1] && dfs(i,j-1);
        };

        return dfs(n-1,m-1);
    }
};