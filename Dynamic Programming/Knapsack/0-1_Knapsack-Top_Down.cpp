#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 3, w = 50;
    // cin >> n >> w;
    int val[n] = {60, 100, 120};
    // for (int i = 0; i < n; ++i)
    //     cin >> val[i];
    int wt[n] = {10, 20, 30};
    // for (int i = 0; i < n; ++i)
    //     cin >> wt[i];
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}