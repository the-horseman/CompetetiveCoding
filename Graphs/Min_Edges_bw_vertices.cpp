#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
using namespace std;

void minEdgeBFS(vi adj[], int u, int v, int n)
{
	vi visited(n, 0);
	vi distance(n, 0);
	visited[u] = 1;
	queue<int> q;
	q.push(u);
	cout << u << " ";
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (auto x : adj[u])
		{
			if (visited[x] != 1)
			{
				visited[x] = 1;
				distance[x] = distance[u] + 1;
				cout << x << " ";
				q.push(x);
			}
		}
	}
	cout << endl
		 << distance[v] << endl;
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int n = 10;
	vector<int> adj[n];
	addEdge(adj, 1,2);
	addEdge(adj, 1,3);
	addEdge(adj, 1,9);
	addEdge(adj, 2,9);
	addEdge(adj, 3,9);
	int u = 3;
	int v = 2;
	minEdgeBFS(adj, u, v, n);
	return 0;
}

// 2+1+1+1