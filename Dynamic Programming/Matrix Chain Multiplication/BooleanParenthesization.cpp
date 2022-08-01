#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int dp[1005][1005][2];

int submain(string &s, int i, int j, int isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lTrue = submain(s, i, k - 1, 1);
        int lFalse = submain(s, i, k - 1, 0);
        int rTrue = submain(s, k + 1, j, 1);
        int rFalse = submain(s, k + 1, j, 0);
        if (s[k] == '^')
        {
            if (isTrue == 1)
                ans += lTrue * rFalse + lFalse * rTrue;
            if (isTrue == 0)
                ans += lTrue * rTrue + lFalse * rFalse;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += lTrue * rTrue + lTrue * rFalse + lFalse * rTrue;
            else
                ans += lFalse * rFalse;
        }
        else
        {
            if (isTrue == 1)
                ans += lTrue * rTrue;
            else
                ans += lTrue * rFalse + lFalse * rTrue + lFalse * rFalse;
        }
    }
    return dp[i][j][isTrue] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s = "T|T&F^T";
    int ans = submain(s, 0, s.length() - 1, 1);
    cout << ans << " ";
    return 0;
}