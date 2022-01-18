#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n=3, w=4;
    // cin>>n>>w;
    int arr[n] = {3,5,2};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>arr[i];
    int dp[n+1][w+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=w ; ++j)
        {
            if (i==0)
                dp[i][j] = INT_MAX-1;
            else
                dp[i][j] = 0;
        }
    }
    for(int i=1 ; i<=w ; ++i)
    {
        if (i%arr[0] == 0)
            dp[1][i] = i/arr[0];
        else
            dp[1][i]=INT_MAX-1;
    }
    for(int i=2 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=w ; ++j)
        {
            if (j-arr[i-1] >=0)
                dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}