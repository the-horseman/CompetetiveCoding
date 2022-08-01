#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int dp[1005][1005];

int submain(int f, int e)
{
    if (e == 1 || f <= 1)
        return f;
    if (dp[f][e] != -1)
        return dp[f][e];
    int ans = 999999;
    for (int i = 1; i <= f; ++i)
    {
        int brk = submain(i - 1, e - 1);
        int nbrk = submain(f - i, e);
        int tmp = 1 + max(brk, nbrk);
        ans = min(ans, tmp);
    }
    return dp[f][e] = ans;
}

int main()
{
    int floors = 10;
    int eggs = 2;
    memset(dp, -1, sizeof(dp));
    int ans = submain(floors, eggs);
    cout << ans << " ";
    return 0;
}