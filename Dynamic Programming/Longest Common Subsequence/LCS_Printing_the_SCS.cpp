#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n = 4, m=3;
    // cin>>n>>m;
    string s1 = "geek", s2 = "eke";
    // cin>>s1>>s2;
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
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
    string ans = "";
    int i=n, j=m;
    while (i>0 && j>0)
    {
        if (s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            --i;
            --j;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
            {
                ans += s1[i-1];
                --i;
            }
            else
            {
                ans += s2[j-1];
                --j;
            }
        }
    }
    while (i>0)
    {
        ans += s1[i-1];
        --i;
    }
    while (j>0)
    {
        ans += s2[j-1];
        --j;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}