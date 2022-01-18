#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;


int main()
{
    int n = 6, m = 6;
    // cin>>n>>m;
    string s1 = "abcdef", s2 = "abedcf";
    // cin>>s1>>s2;
    string ans = "";
    int dp[n+1][m+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if (i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m]<< endl;
    // Printing the LCS
    int i=n,j=m;
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
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}