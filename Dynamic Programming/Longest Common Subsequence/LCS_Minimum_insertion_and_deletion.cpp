#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 4, m = 3;
    // cin>>n>>m;
    string s1 = "heap", s2 = "pea";
    // cin >> s1 >> s2;
    int dp[n+1][m+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if (i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int del = n-dp[n][m];
    int ins = m-dp[n][m];
    cout<<ins<<" "<<del<<endl;
    return 0;
}