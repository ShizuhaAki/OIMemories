#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200020;
int n, a[MAXN], fa[MAXN];
bool vis[MAXN];
vector <int> g[MAXN];
int sz[MAXN];
int root;
typedef vector <int> :: iterator IT;
int findset(int x)
{
	return (x == fa[x]) ? x : (fa[x] = findset(fa[x]));
}
void mergeset(int x, int y)
{
	int xx = findset(x), yy = findset(y);
	fa[xx] = yy;
}
bool bfs(int s)
{
	cerr << "bfs(" << s << "):" << endl;
	int csz = 0;
	queue <int> q;
	q.push(s);
	if (fa[s] == s)return false;
	vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
	//	if (g[u].size() == 0)continue;
		for (IT it = g[u].begin(); it != g[u].end(); it++)
		{
			cerr << *it << endl;
			int v = *it;
			if (vis[v])
			{
				g[u][v] = 0;
				fa[u] = u;
				sz[u] += csz;
				return false;
			}
			vis[v] = true;
			q.push(v);
			csz++;
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		g[i].push_back(a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = a[i];
		if (fa[i] == i)cnt++;
	}
	if (cnt == 1)
	{
		cout << 0 << endl;
		for (int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])bfs(i);
	cnt = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
		{
			cnt++;
			if (cnt == 1)root = i;
			if (cnt > 1)
				if (sz[root] > sz[i])
					root = i;
		}
	for (int i = 1; i <= n; i++)cerr << sz[i] << ' ';cerr << endl;
	cerr << root << endl;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			if (i != root)
				mergeset(i, root);
	cnt = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] != a[i])cnt++;
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		cout << fa[i] << ' ';
	cout << endl;
	return 0;
}

