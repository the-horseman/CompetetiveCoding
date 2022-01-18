#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vi adj[n];
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	vi deg(n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (auto x : adj[i])
		{
			deg[x]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < deg.size(); ++i)
	{
		if (deg[i] == 0)
			q.push(i);
	}

	int cnt = 0;

	vi ans;
	while (q.empty() == 0)
	{
		int u = q.front();
		q.pop();
		ans.push_back(u + 1);
		for (auto x : adj[u])
		{
			deg[x]--;
			if (deg[x] == 0)
				q.push(x);
		}
		cnt++;
	}
	if (cnt != n)
		cout << -1 << endl;
	else
	{
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}