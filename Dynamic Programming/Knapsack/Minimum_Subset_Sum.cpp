#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    int n = 4;
    // cin>>n;
    int arr[n] = {1,6,11,5};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>arr[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    int w = sum / 2;
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=w ; ++j)
        {
            if (j - arr[i-1]>=0)
                dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];            
        }
    }
    int sum1 = dp[n][w];
    int sum2 = sum - sum1;
    int ans = abs(sum1-sum2);
    cout<<ans<<endl;
    return 0;
}