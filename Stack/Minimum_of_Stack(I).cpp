#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

void ppush(stack<int> &s, stack<int> &ss, int ele)
{
    s.push(ele);
    if (ss.size() == 0 || ss.top() >= ele)
        ss.push(ele);
}
void ppop(stack<int> &s, stack<int> &ss)
{
    if (s.top() == ss.top())
        ss.pop();
    s.pop();
}
int getmin(stack<int> &ss)
{
    return ss.top();
}

int main()
{
    stack<int> s;
    stack<int> ss;

    return 0;
}