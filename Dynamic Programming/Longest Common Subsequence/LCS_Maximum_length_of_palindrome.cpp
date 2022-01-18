#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n = 8;
    // cin>>n;
    string s1 = "abghcbda";
    // cin>>s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = n;
    int dp[n+1][m+1];
    memset(dp, 0 ,sizeof(dp));
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}