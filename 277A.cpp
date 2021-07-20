#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
vector <int> g[MAXN];
int vis[MAXN], n, m;
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (vector <int> :: iterator it = g[u].begin(); it != g[u].end(); it++)
		{
			int v = *it;
			if (vis[v])continue;
			vis[v] = true;
			q.push(v);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		if (k)flag = false;
		for (int j = 1; j <= k; j++)
		{
			int v;
			cin >> v;
			g[i].push_back(v + n);
			g[v + n].push_back(i);
		}
	} 
	if (flag)
	{
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			bfs(i);
			ans++;
		}
	cout << ans - 1 << endl;
	return 0;
}

