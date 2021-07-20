#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200020;
vector <int> g[MAXN];
int vis[MAXN];
int n, m;
int ans = 0;
bool flg = true;
void dfs(int now)
{
	if (vis[now])return;
	vis[now] = true;
	if (g[now].size() != 2)flg = false;
	for (auto i:g[now])dfs(i);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			flg = true;
			dfs(i);
			if (flg)ans++;
		}
	cout << ans << endl;
	return 0;
}

