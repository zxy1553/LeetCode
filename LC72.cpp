#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
    int minDistance(string word1, string word2){
        int n = word1.length();
        int m = word2.length();

        if(n*m == 0) return n+m;

        vector D(n+1, vector<int>(m+1));

        for (int i = 0; i < n+1; i++)
        {
            D[i][0] = i;
        }
        for(int j=0; j<m+1; ++j){
            D[0][j] = j;
        }

        for (int i = 1; i < n+1 ; i++)
        {
            for (int j = 1; j < m+1; j++)
            {
                if(word1[i-1]!=word2[j-1]){
                    D[i][j]=1+min(D[i][j-1],min(D[i-1][j],D[i-1][j-1]));
                }else{
                    D[i][j]=D[i-1][j-1];
                }
            }
            
        }
        
        

        return D[n][m];
    }
};