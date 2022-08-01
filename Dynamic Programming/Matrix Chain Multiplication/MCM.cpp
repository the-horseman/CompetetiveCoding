#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int dp[1005][1005];

int submain(vi &arr, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 999999;
    for (int k = i; k < j; ++k)
    {
        int lf = submain(arr, i, k);
        int rt = submain(arr, k + 1, j);
        int cur = arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, lf + rt + cur);
    }
    return dp[i][j] = ans;
}

int main()
{
    vi arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    int ans = submain(arr, 1, n - 1);
    cout << ans << " ";
    return 0;
}