#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

vector <vi> dp(110, vi (110, -1));

int submain(vector<vector<int>> &obs, int n, int m)
{
    if (n == 0 && m == 0)
        return 1;
    else if (dp[n][m] != -1)
        return dp[n][m];
    else
    {
        if (obs[n][m] == 1)
            return dp[n][m] = 0;
        else if (n != 0 && m != 0)
            return dp[n][m] = submain(obs, n - 1, m) + submain(obs, n, m - 1);
        else if (n != 0 && m == 0)
            return dp[n][m] = submain(obs, n - 1, m);
        else
            return dp[n][m] = submain(obs, n, m - 1);
    }
    return dp[n][m];
}
int uniquePathsWithObstacles(vector<vector<int>> &obs)
{
    int n = obs.size();
    int m = obs[0].size();
    if (obs[0][0] == 1)
        return 0;
    else
        return submain(obs, n - 1, m - 1);
}

int main()
{
    vector <vi> obs = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout<<uniquePathsWithObstacles(obs);
    return 0;
}