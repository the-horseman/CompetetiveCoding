#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    int n=3, sum=5;
    // cin>>n;
    int arr[n]={1,2,3};
    // for(int i=0 ; i<n ; ++i)
    //     cin>>arr[i];
    int dp[n+1][sum+1];
    for(int i=0 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=sum ; ++j)
        {
            if (j==0)
                dp[i][j]=1;
            else   
                dp[i][j]=0;
        }
    }
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<=sum ; ++j)
        {
            if (j-arr[i-1]>=0)
                dp[i][j] = dp[i][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
    return 0;
}