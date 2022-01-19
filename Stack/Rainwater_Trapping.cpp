#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    vector <int> arr = {3,0,0,2,0,4};
    vector <int> lf;
    vector <int> rt;
    int n = arr.size();
    lf.push_back(arr[0]);
    for(int i=1 ; i<n ; ++i)
    {
        if (lf[i-1]<arr[i])
            lf.push_back(arr[i]);
        else
            lf.push_back(lf[i-1]);
    }
    vector <int> rev (arr.begin(), arr.end());
    reverse(rev.begin(), rev.end());
    rt.push_back(rev[0]);
    for(int i=1 ; i<n ; ++i)
    {
        if (rt[i-1]<arr[i])
            rt.push_back(arr[i]);
        else
            rt.push_back(rt[i-1]);
    }
    int water = 0;
    for(int i=0 ; i<n ; ++i)
    {
        int val = min(lf[i], rt[i]);
        val = val - arr[i];
        water += val;
    }
    cout<<water<<endl;
    return 0;
}