#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int dp[1005][1005];

bool isPal(string &s, int &i, int &j)
{
    string cur = s.substr(i, j - i + 1);
    reverse(cur.begin(), cur.end());
    if (s.substr(i, j - i + 1) == cur)
        return true;
    return false;
}

int submain(string &s, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isPal(s, i, j))
        return dp[i][j] = 0;
    int ans = 999999;
    for (int k = i; k < j; ++k)
    {
        int lf = submain(s, i, k);
        int rt = submain(s, k + 1, j);
        ans = min(ans, lf + rt + 1);
    }
    return dp[i][j] = ans;
}

int main()
{
    string s = "geek";
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    int ans = submain(s, 0, n - 1);
    cout << ans << " ";
    return 0;
}