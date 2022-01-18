#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n=5, w=6;
    // cin>>n>>w;
    int arr[n] = {1,2,3,5,6};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>arr[i];
    int dp[n+1][w+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=w ; ++j)
        {
            if(j==0)
                dp[i][j]=1;
            else
                dp[i][j]=0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=w ; ++j)
        {
            if(j-arr[i-1]>=0)
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}