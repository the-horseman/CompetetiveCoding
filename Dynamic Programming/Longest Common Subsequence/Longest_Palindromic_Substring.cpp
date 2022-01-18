#include <bits/stdc++.h>

#define mod 1000000007
#define INF 1000000005
#define INFL 1000000000000000005ll
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define pii pair<int, int>
#define vi vector<int>
#define vp vector<pii>
#define ll long long

using namespace std;

string longestPalindrome(string s)
{
    string ans = "";
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int len = INT_MIN;
    int strt = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                if (j - i == 0)
                    dp[i][j] = 1;
                else if (j - i == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j] == 1 && (j - i + 1) > len)
            {
                len = j - i + 1;
                strt = i;
            }
        }
    }
    ans = s.substr(strt, len);
    return ans;
}

int main()
{
    string s = "cbbd";
    cout << longestPalindrome(s);

    return 0;
}