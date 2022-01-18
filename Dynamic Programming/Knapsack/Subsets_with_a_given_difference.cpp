#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 4, dif = 1;
    // cin>>n;
    int arr[n] = {1, 1, 2, 3};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>arr[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    int w = (sum + dif) / 2;
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
            if (j - arr[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}