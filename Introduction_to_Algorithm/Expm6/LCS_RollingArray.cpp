#include <iostream>
#include <string.h>
using namespace std;
 
/* 滚动数组 */
 
int dp[2][21];  /* 存储LCS长度 */
int i, j, k;
 
int main()
{
	string X = "ADBCABC";
	string Y = "BDAC";
 
    int xlen = X.length();
    int ylen = Y.length();
 
    for(i = 1; i <= xlen; ++i)
    {
        k = i & 1;
        for(j = 1; j <= ylen; ++j)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[k][j] = dp[k^1][j-1] + 1;
            }else if(dp[k][j-1] > dp[k^1][j])
            {
                dp[k][j] = dp[k][j-1];
            }else
            {
                dp[k][j] = dp[k^1][j];
            }
        }
    }
    cout << "The length of LCS is: " << dp[k][ylen] << endl;
	return 0;
}