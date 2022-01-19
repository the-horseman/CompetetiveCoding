#include<bits/stdc++.h>

#define ll long long
#define vi vector <int>
using namespace std;

int ttop(stack <int> &s, int &min_ele)
{
    if (s.top() <= min_ele)
        return min_ele;
    else
        return s.top();
}

void ppush(stack <int> &s, int &min_ele, int ele)
{
    if (ele<=min_ele)
    {
        min_ele = ele;
        s.push(2*ele-min_ele);
    }
    else
        s.push(ele);
}

void ppop(stack <int> &s, int &min_ele)
{
    if (s.top() <= min_ele)
    {
        min_ele = 2*min_ele-s.top();
    }
    s.pop();
}

int get_min(int &min_ele)
{
    return min_ele;
}

int main()
{
    stack <int> s;
    int min_ele;
    return 0;
}