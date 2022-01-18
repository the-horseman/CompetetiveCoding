#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    stack<pair<int,int>> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        if (s.size() == 0 || s.top().first > arr[i])
        {
            ans.push_back(1);
            s.push(make_pair(arr[i],i));
        }
        else
        {
            while (s.size() > 0 && s.top().first < arr[i])
            {
                s.pop();
            }
            ans.push_back(i-s.top().second);
            s.push(make_pair(arr[i],i));
        }
    }
    for(int i=0 ; i<ans.size() ; ++i)
        cout<<ans[i]<<" ";
    return 0;
}