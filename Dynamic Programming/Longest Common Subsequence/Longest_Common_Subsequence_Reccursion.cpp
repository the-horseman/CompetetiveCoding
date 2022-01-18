#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;

int LCS(string s1, string s2, int n, int m)
{
    if (n==0 || m==0)
        return 0;
    if (s1[n-1] == s2[m-1])
        return (1+LCS(s1,s2,n-1,m-1));
    else
        return max(LCS(s1,s2,n-1,m), LCS(s1,s2,n,m-1));
}

int main()
{
    int n=6,m=7;
    // cin>>n>>m;
    string s1 = "abcdef",s2 = "abedgfr";
    // cin>>s1>>s2;
    cout<<LCS(s1,s2,n,m)<<endl;
    return 0;
}