#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 4;
    // cin >> n >> w;
    int arr[n] = {1, 5, 11, 5};
    // for (int i = 0; i < n; ++i)
    //     cin >> arr[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    if (sum % 2 == 0)
    {
        int w = sum / 2;
        int dp[n + 1][w + 1];
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= w; ++j)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= w; ++j)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][w] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}