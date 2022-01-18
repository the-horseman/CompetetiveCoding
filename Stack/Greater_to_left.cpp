#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
    vector<int> arr = {4, 2, 3, 1};
    stack<int> s;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        if (s.size() == 0)
        {
            ans.push_back(-1);
            s.push(arr[i]);
        }
        else if (s.top() <= arr[i])
        {
            while (s.top() <= arr[i] && s.size() > 0)
            {
                s.pop();
            }
            if (s.size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}