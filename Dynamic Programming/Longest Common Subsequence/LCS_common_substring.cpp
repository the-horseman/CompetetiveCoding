#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 6, m = 6;
    // cin>>n>>m;
    string s1 = "abcdef", s2 = "abdcgf";
    // cin>>s1>>s2;
    int dp[n + 1][m + 1];
    int mx = INT_MIN;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = 0;
            mx = max(dp[i][j], mx);
        }
    }
    cout<<mx<<endl;
    return 0;
}