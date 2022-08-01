#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

unordered_map<string, int> m;

bool submain(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int n = s.length();
    if (n == 0)
        return true;
    if (s == t)
        return true;
    string key = s + " " + t;
    if (m.find(key) != m.end())
        return m[key];
    bool ans = false;
    for (int i = 1; i < n; ++i)
    {
        bool cond1 = submain(s.substr(0, i), t.substr(0, i)) && submain(s.substr(i, n - i), t.substr(i, n - i));
        bool cond2 = submain(s.substr(0, i), t.substr(n - i, i)) && submain(s.substr(i, n - i), t.substr(0, n - i));
        if (cond1 || cond2)
        {
            ans = true;
            break;
        }
    }
    return m[key] = ans;
}

int main()
{
    string s = "coder";
    string t = "great";
    bool ans = submain(s, t);
    cout << ans;
    return 0;
}
