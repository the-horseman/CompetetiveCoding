#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int dp[10000][10000];

int knapsack(int val[], int wt[], int w, int n)
{
    if (n == 0 || w == 0)
        return dp[n][w] = 0;
    else if (dp[n][w] != -1)
        return dp[n][w];
    else if (wt[n - 1] <= w)
    {
        int x = knapsack(val, wt, w - wt[n - 1], n - 1);
        int y = knapsack(val, wt, w, n - 1);
        return dp[n][w] = max((val[n - 1] + x), y);
    }
    else
    {
        int y = knapsack(val, wt, w, n - 1);
        return dp[n][w] = y;
    }
}

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
    memset(dp, -1, sizeof(dp));
    cout << knapsack(val, wt, w, n) << endl;
    return 0;
}