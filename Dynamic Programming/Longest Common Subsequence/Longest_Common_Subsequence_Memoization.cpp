#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int dp[100][100];

int LCS(string s1, string s2, int n, int m)
{
    if (n==0 || m==0)
        return dp[n][m] = 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    else if (s1[n-1] == s2[m-1])
        return dp[n][m] = 1+LCS(s1, s2, n-1, m-1);
    else
        return dp[n][m] = max(LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1));
}

int main()
{
    int n = 7, m = 7;
    // cin>>n>>m;
    string s1 = "abcdefg", s2 = "abedgfr";
    // cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    cout<<LCS(s1, s2, n, m)<<endl;
    return 0;
}