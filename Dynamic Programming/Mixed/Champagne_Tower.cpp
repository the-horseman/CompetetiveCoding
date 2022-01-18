#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(110, vector<double>(110, 0));
    dp[0][0] = (double)poured;
    for (int i = 0; i <= query_row; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            double left = (dp[i][j] - 1.0) * 0.5;
            if (left > 0)
            {
                dp[i + 1][j + 1] += left;
                dp[i + 1][j] += left;
            }
        }
    }
    return min(1.0, dp[query_row][query_glass]);
}

int main()
{
    cout<<champagneTower(2,1,1);
    return 0;
}