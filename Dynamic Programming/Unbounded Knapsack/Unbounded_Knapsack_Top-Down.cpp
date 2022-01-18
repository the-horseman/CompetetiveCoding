#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 4, w = 8;
    // cin>>n>>w;
    int val[n] = {10, 40, 50, 70};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>val[i];
    int wt[n] = {1, 3, 4, 5};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>wt[i];
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            if (j - wt[i - 1] >= 0)
                dp[i][j] = max((val[i - 1] + dp[i][j - wt[i - 1]]), dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}