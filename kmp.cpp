#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (m == 0)
            return 0;
        if (n < m)
            return -1;

        // generate optimized nextval vector
        vector<int> nextval(m, 0);
        nextval[0] = -1;
        int j = 0, k = -1;
        while (j < m - 1)
        {
            if (k == -1 || p[j] == p[k])
            {
                j++;
                k++;
                // 若p[j]==p[k],则继承nextval[k]的值
                nextval[j] = (p[j] != p[k]) ? k : nextval[k];
            }
            else
            {
                k = nextval[k];
            }
        }

        // KMP匹配过程
        int i = 0; j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || s[i] == p[j])
            {
                j++;
                i++;
            }
            else
            {
                j = nextval[j];
            }
        }
        return (j == m) ? i - j : -1;
    }
};
