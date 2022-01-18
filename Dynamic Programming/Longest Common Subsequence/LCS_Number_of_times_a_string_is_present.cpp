#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n=10, m=8;
    // cin>>n>>m;
    string s1 = "chchokudai", s2 = "chokudai";
    // cin>>s1>>s2;
    int dp[n+1][m+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if (j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}