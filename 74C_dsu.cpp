#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
namespace dsu
{
	int fa[MAXN * 5];
	void make_set(int n)
	{
		for (int i = 1; i <= n; i++)fa[i] = i;
	}
	int find(int x)
	{
		return (x == fa[x]) ? x : fa[x] = find(fa[x]);
	}
	void merge(int x, int y)
	{
		int xx = find(x), yy = find(y);
		if (xx != yy)fa[yy] = xx;
	} 
	int count(int n)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)if (fa[i] == i)res++;
		return res;
	}
}
int n, m, c;
int main()
{
	dsu::make_set(5 * MAXN);
	cin >> n >> m; c = n + m - 3;
	for (int i = 2; i <= n - 1; i++)dsu::merge(i - 1, n  - i + c), 
									dsu::merge(m - 2 + i, n + m - i - 1 + c);
	for (int i = 2; i <= m - 1; i++)dsu::merge(i - 1, n - 2 + i + c), 
									dsu::merge(n - 2 + i, i - 1 + c);
	cout << dsu::count(c << 1) << endl;
	return 0;
}

