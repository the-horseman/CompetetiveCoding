#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n=6;
    // cin>>n;
    string s1 = "agbcba";
    // cin>>s1;
    string s2 = s1; 
    reverse(s2.begin(), s2.end());
    int m = n;
    int dp[n][m];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
        }
    }    
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int ans = n-dp[n][m];
    cout<<ans<<endl;
    return 0;
}