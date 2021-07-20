#include <iostream>
using namespace std;
int n;
const int MAXN = 150010;
int fa[MAXN];
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int xx = find(x), yy = find(y);
	fa[yy] = xx;
}
int lchild[MAXN << 2], rchild[MAXN << 2];
int used;
void dfs(int now)
{
	if (lchild[now] == -1)
	{
		cout << now << ' ';
		return;
	}
	else
	{
		dfs(lchild[now]);
		dfs(rchild[now]);
	}
}
int mp[MAXN << 2];
int main()
{
	cin >> n;
	make_set(n);
	for (int i = 1; i <= n; i++)
	{
		lchild[i] = -1;
		rchild[i] = -1;
		mp[i] = i;
	}
	used = n;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		lchild[++used] = mp[find(x)];
		rchild[used] = mp[find(y)];
		merge(x, y);
		mp[find(x)] = used;
	}
	dfs(used);
	cout << endl;
	return 0;
}
