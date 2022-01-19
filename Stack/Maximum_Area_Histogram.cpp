#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;


int main()
{
    vector <int> arr = {6,2,5,4,5,1,6};
    vector <int> nsl;
    stack <pair<int, int>> s;
    int n = arr.size();
    for(int i=0 ; i<n ; ++i)
    {
        if (s.size() == 0)
        {
            nsl.push_back(-1);
            s.push(make_pair(arr[i],i));
        }
        else if (s.top().first>=arr[i])
        {
            while (s.size()>0 && s.top().first >=arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                nsl.push_back(-1);
            else
                nsl.push_back(s.top().second);
            s.push(make_pair(arr[i], i));
        }
        else
        {
            nsl.push_back(s.top().second);
            s.push(make_pair(arr[i], i));
        }
    }
    vector <int> nsr;
    stack <pair<int,int>> s1;
    for(int i=n-1 ; i>=0 ; --i)
    {
        if (s1.size() == 0)
        {
            nsr.push_back(n);
            s1.push(make_pair(arr[i], i));
        }
        else if (s1.top().first >= arr[i])
        {
            while (s1.size()>0 && s1.top().first >= arr[i])
            {
                s1.pop();
            }
            if (s1.size() > 0)
                nsr.push_back(s1.top().second);
            else
                nsr.push_back(n);
            s1.push(make_pair(arr[i], i));
        }
        else
        {
            nsr.push_back(s1.top().second);
            s1.push(make_pair(arr[i], i));
        }
    }
    reverse(nsr.begin(), nsr.end());
    vector <int> width;
    for(int i=0 ; i<n ; ++i)
    {
        int lf = i-nsl[i]-1;
        int rf = nsr[i]-i;
        width.push_back(lf+rf);
    }
    int mx = INT_MIN;
    for(int i=0 ; i<n ; ++i)
    {
        mx = max(mx, width[i]*arr[i]);
    }
    cout<<mx;
    return 0;
}