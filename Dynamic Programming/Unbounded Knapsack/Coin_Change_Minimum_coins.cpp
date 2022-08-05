#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int dp[15][10005];
int submain(vector<int> &arr, int amt, int ind)
{
    if (amt == 0)
        return 0;
    if (dp[ind][amt] != -1)
        return dp[ind][amt];
    int ans = 99999;
    for (int i = ind; i < arr.size(); ++i)
    {
        if (amt - arr[i] >= 0)
            ans = min(ans, 1 + submain(arr, amt - arr[i], i));
    }
    return dp[ind][amt] = ans;
}

int main()
{
    vi arr = {1, 2, 5};
    int amt = 11;
    memset(dp, -1, sizeof(dp));
    int ans = submain(arr, amt, 0);
    cout << ans;
    return 0;
}