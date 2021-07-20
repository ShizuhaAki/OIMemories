#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
struct dsu
{
	int fa[N];
	int find(int x)
	{
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void merge(int x, int y)
	{
		int xx = find(x), yy = find(y);
		if (xx == yy)return;
		fa[xx] = yy;
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
	dsu(int n)
	{
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
} ;
int n, a[N], vis[N], root = -1, ans;
int dfs(int x)
{
	if (vis[x]) return x;
	vis[x] = true;
	return dfs(a[x]);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)if (a[i] == i)root = i;
	if (root == -1)
	{
		root = dfs(1);
		ans++;
		a[root] = root;
		memset(vis, 0, sizeof(vis)); 
	}
	dsu u(n);
	for (int i = 1; i <= n; i++)u.merge(i, a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (u.same(i, root))continue;
		int now = dfs(i);
		ans++;
		a[now] = root;
		u.merge(root, i);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)cout << a[i] << ' ';
	cout << endl;
	return 0;
}

